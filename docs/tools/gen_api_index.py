#!/usr/bin/env python3
from __future__ import annotations

import argparse
from pathlib import Path


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate a placeholder AXCL API index page.")
    parser.add_argument("xml_dir", type=Path, help="Path to the Doxygen XML directory")
    parser.add_argument("output", type=Path, help="RST file to write")
    args = parser.parse_args()

    xml_files = sorted(args.xml_dir.glob("*.xml")) if args.xml_dir.exists() else []
    lines = [
        "Generated API Index",
        "===================",
        "",
        ".. note::",
        "",
        "   This is a placeholder generator used during repository bootstrap.",
        "   Replace it with function-oriented grouping once the XML schema is finalized.",
        "",
        f"Detected XML files: {len(xml_files)}",
        "",
    ]

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text("\n".join(lines) + "\n", encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())