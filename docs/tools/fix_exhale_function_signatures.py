from __future__ import annotations

import re
import xml.etree.ElementTree as ET
from pathlib import Path

_DIRECTIVE_RE = re.compile(r"^\.\. doxygenfunction::\s*(.+)$", re.MULTILINE)
_WHITESPACE_RE = re.compile(r"\s+")


def _flatten_text(element: ET.Element | None) -> str:
    if element is None:
        return ""
    return "".join(element.itertext())


def _normalize_token_spacing(value: str) -> str:
    value = _WHITESPACE_RE.sub(" ", value).strip()
    return value


def _build_signature(memberdef: ET.Element) -> str:
    name = memberdef.findtext("name", default="")
    params: list[str] = []
    for param in memberdef.findall("param"):
        param_type = _normalize_token_spacing(_flatten_text(param.find("type")))
        array_suffix = (param.findtext("array") or "").strip()
        if array_suffix:
            params.append(f"{param_type} {array_suffix}".strip())
        else:
            params.append(param_type)
    return f"{name}({', '.join(params)})" if params else f"{name}()"


def _count_params(signature: str) -> int:
    start = signature.find("(")
    end = signature.rfind(")")
    if start == -1 or end == -1 or end <= start + 1:
        return 0
    body = signature[start + 1 : end].strip()
    if not body or body == "void":
        return 0
    return body.count(",") + 1


def _collect_signatures(xml_dir: Path) -> dict[str, list[str]]:
    signatures: dict[str, list[str]] = {}
    for xml_path in sorted(xml_dir.glob("*.xml")):
        try:
            root = ET.parse(xml_path).getroot()
        except ET.ParseError:
            continue
        for memberdef in root.findall(".//memberdef[@kind='function']"):
            signature = _build_signature(memberdef)
            name = memberdef.findtext("name", default="")
            signatures.setdefault(name, []).append(signature)
    return signatures


def _choose_signature(current: str, candidates: list[str]) -> str | None:
    if not candidates:
        return None
    if len(candidates) == 1:
        return candidates[0]

    current_count = _count_params(current)
    same_arity = [candidate for candidate in candidates if _count_params(candidate) == current_count]
    if len(same_arity) == 1:
        return same_arity[0]
    if same_arity:
        return same_arity[0]
    return candidates[0]


def patch_exhale_function_signatures(api_root_dir: Path, xml_dir: Path) -> int:
    if not api_root_dir.exists() or not xml_dir.exists():
        return 0

    signatures = _collect_signatures(xml_dir)
    updated = 0
    for rst_path in sorted(api_root_dir.glob("function_*.rst")):
        content = rst_path.read_text(encoding="utf-8")
        match = _DIRECTIVE_RE.search(content)
        if match is None:
            continue

        current = match.group(1).strip()
        function_name = current.split("(", 1)[0].strip()
        replacement = _choose_signature(current, signatures.get(function_name, []))
        if replacement is None or replacement == current:
            continue

        new_content = _DIRECTIVE_RE.sub(
            f".. doxygenfunction:: {replacement}", content, count=1
        )
        if new_content == content:
            continue

        rst_path.write_text(new_content, encoding="utf-8")
        updated += 1

    return updated
