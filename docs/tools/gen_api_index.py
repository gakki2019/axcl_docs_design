#!/usr/bin/env python3
from __future__ import annotations

import argparse
import xml.etree.ElementTree as ET
from pathlib import Path


def _flatten_text(element: ET.Element | None) -> str:
    if element is None:
        return ""
    return " ".join(part.strip() for part in element.itertext() if part.strip())


def _sanitize_name(value: str) -> str:
    cleaned = []
    for char in value:
        cleaned.append(char if char.isalnum() else "_")
    return "".join(cleaned).strip("_") or "group"


def generate_api_index(xml_dir: Path, output: Path) -> None:
    output.parent.mkdir(parents=True, exist_ok=True)
    for stale_file in output.parent.glob("group_*.rst"):
        stale_file.unlink()

    group_files = sorted(xml_dir.glob("group__*.xml")) if xml_dir.exists() else []
    groups: list[dict[str, object]] = []

    for group_file in group_files:
        root = ET.parse(group_file).getroot()
        compound = root.find("compounddef")
        if compound is None:
            continue

        group_name = _flatten_text(compound.find("compoundname"))
        title = _flatten_text(compound.find("title")) or group_name
        functions: list[dict[str, str]] = []
        for section in compound.findall("sectiondef"):
            if section.attrib.get("kind") != "func":
                continue
            for member in section.findall("memberdef"):
                if member.attrib.get("kind") != "function":
                    continue
                member_id = member.attrib.get("id", "")
                name = _flatten_text(member.find("name"))
                summary = _flatten_text(member.find("briefdescription")) or "No summary available."
                if member_id and name:
                    functions.append({
                        "id": member_id,
                        "name": name,
                        "summary": summary,
                    })

        if functions:
            functions.sort(key=lambda item: item["name"])
            slug = f"group_{_sanitize_name(group_name)}"
            groups.append({
                "name": group_name,
                "title": title,
                "slug": slug,
                "functions": functions,
            })

    if not groups:
        output.write_text(
            """C/C++ API Reference
===================

.. note::

   No grouped functions were discovered in the Doxygen XML output.
""",
            encoding="utf-8",
        )
        return

    root_lines = [
        "C/C++ API Reference",
        "===================",
        "",
        "This page is the public entry for the generated C/C++ API. Functions are grouped by the Doxygen groups declared in the public headers.",
        "",
        ".. toctree::",
        "   :hidden:",
        "",
    ]

    for group in groups:
        root_lines.append(f"   {group['slug']}")

    root_lines.extend([
        "",
        "API Groups",
        "----------",
        "",
    ])

    for group in groups:
        title = str(group["title"])
        slug = str(group["slug"])
        root_lines.append(f"- :doc:`{title} <{slug}>`")

        group_lines = [
            title,
            "=" * len(title),
            "",
            f"Function-oriented entry page for the ``{group['name']}`` Doxygen group.",
            "",
            ".. list-table::",
            "   :header-rows: 1",
            "   :widths: 30 70",
            "",
            "   * - Function",
            "     - Summary",
        ]

        for function in group["functions"]:
            group_lines.extend([
                f"   * - :doc:`{function['name']} <function_{function['id']}>`",
                f"     - {function['summary']}",
            ])

        (output.parent / f"{slug}.rst").write_text("\n".join(group_lines) + "\n", encoding="utf-8")

    output.write_text("\n".join(root_lines) + "\n", encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate a function-oriented AXCL API index page.")
    parser.add_argument("xml_dir", type=Path, help="Path to the Doxygen XML directory")
    parser.add_argument("output", type=Path, help="RST file to write")
    args = parser.parse_args()
    generate_api_index(args.xml_dir, args.output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())