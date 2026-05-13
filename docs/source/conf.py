from __future__ import annotations

import importlib.util
import re
import shutil
import subprocess
from pathlib import Path
from typing import Any

project = "AXCL Documentation"
author = "Axera Semiconductor"
copyright = "2026, Axera Semiconductor"

ROOT_DIR = Path(__file__).resolve().parents[2]
SOURCE_DIR = Path(__file__).resolve().parent
BUILD_DIR = ROOT_DIR / "docs" / "build"
DOXYGEN_DIR = BUILD_DIR / "doxygen"
DOXYGEN_XML_DIR = DOXYGEN_DIR / "xml"
HEADERS_DIR = ROOT_DIR / "include" / "external"
API_ROOT_DIR = SOURCE_DIR / "en" / "dev" / "c" / "generated"
API_ROOT_FILE = API_ROOT_DIR / "api_root.rst"

LANGUAGE_LABELS = {
    "en": "English",
    "zh": "中文",
}

NAV_TITLES = {
    "en": {
        "basic": "Basic",
        "overview": "Overview",
        "install": "Installation",
        "quick_start": "Quick Start",
        "development": "Development",
        "architecture": "Architecture",
        "c_api": "C/C++ API",
        "python_api": "Python API",
        "faq": "FAQ",
    },
    "zh": {
        "basic": "基础",
        "overview": "概览",
        "install": "安装指南",
        "quick_start": "快速开始",
        "development": "开发",
        "architecture": "架构",
        "c_api": "C/C++ API",
        "python_api": "Python API",
        "faq": "FAQ",
    },
}


def load_tool_function(module_name: str, file_name: str, function_name: str):
    module_path = ROOT_DIR / "docs" / "tools" / file_name
    spec = importlib.util.spec_from_file_location(module_name, module_path)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"Unable to load {function_name} from {module_path}")

    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return getattr(module, function_name)


generate_api_index = load_tool_function(
    "gen_api_index", "gen_api_index.py", "generate_api_index"
)
patch_exhale_function_signatures = load_tool_function(
    "fix_exhale_function_signatures",
    "fix_exhale_function_signatures.py",
    "patch_exhale_function_signatures",
)


def write_api_placeholder(reason: str) -> None:
    API_ROOT_DIR.mkdir(parents=True, exist_ok=True)
    API_ROOT_FILE.write_text(
        """C/C++ API Reference
===================

.. note::

   API generation is currently in placeholder mode.

   Reason: {reason}

   Install the Python requirements from ``docs/requirements.txt`` and make sure
   ``doxygen`` is available in ``PATH`` before building the full API reference.
""".format(reason=reason),
        encoding="utf-8",
    )


def can_enable_api_extensions() -> bool:
    return all(
        importlib.util.find_spec(module) is not None for module in ("breathe", "exhale")
    )


def run_doxygen() -> tuple[bool, str]:
    doxygen = shutil.which("doxygen")
    if doxygen is None:
        return False, "doxygen is not installed"

    DOXYGEN_DIR.mkdir(parents=True, exist_ok=True)
    config_lines = [
        "PROJECT_NAME = AXCL Documentation",
        f"OUTPUT_DIRECTORY = {DOXYGEN_DIR}",
        f"INPUT = {HEADERS_DIR}",
        "FILE_PATTERNS = *.h",
        "RECURSIVE = YES",
        "ENABLE_PREPROCESSING = YES",
        "MACRO_EXPANSION = YES",
        "EXPAND_ONLY_PREDEF = YES",
        "PREDEFINED = AXCL_EXPORT=",
        "GENERATE_HTML = NO",
        "GENERATE_LATEX = NO",
        "GENERATE_XML = YES",
        "XML_OUTPUT = xml",
        "EXTRACT_ALL = NO",
        "WARN_IF_UNDOCUMENTED = YES",
        "WARN_IF_DOC_ERROR = YES",
        "QUIET = YES",
    ]
    doxyfile = DOXYGEN_DIR / "Doxyfile"
    doxyfile.write_text("\n".join(config_lines) + "\n", encoding="utf-8")

    try:
        subprocess.run([doxygen, str(doxyfile)], check=True)
    except subprocess.CalledProcessError as exc:
        return False, f"doxygen failed with exit code {exc.returncode}"

    return True, "ok"


extensions: list[str] = []
if can_enable_api_extensions():
    ok, message = run_doxygen()
    if ok:
        generate_api_index(DOXYGEN_XML_DIR, API_ROOT_FILE)
        extensions = ["breathe", "exhale"]
    else:
        write_api_placeholder(message)
else:
    write_api_placeholder("breathe and exhale are not installed")

breathe_projects = {"axcl": str(DOXYGEN_XML_DIR)} if extensions else {}
breathe_default_project = "axcl"
exhale_args = {
    "containmentFolder": str(API_ROOT_DIR),
    "rootFileName": "exhale_root.rst",
    "rootFileTitle": "C/C++ API Details",
    "doxygenStripFromPath": str(ROOT_DIR),
    "createTreeView": False,
    "exhaleExecutesDoxygen": False,
    "contentsDirectives": False,
} if extensions else {}

templates_path = ["_templates"]
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]
html_static_path = ["_static"]
html_theme = "sphinx_rtd_theme"
html_logo = "_static/img/axcl-logo.svg"
html_css_files = ["css/custom.css"]
html_js_files = ["js/nav_toggle.js"]
html_theme_options = {
    "collapse_navigation": False,
    "sticky_navigation": True,
    "navigation_depth": 4,
    "includehidden": True,
    "titles_only": False,
}
html_show_sourcelink = False
html_title = project
master_doc = "index"


def discover_source_docnames() -> set[str]:
    docnames: set[str] = set()
    for path in SOURCE_DIR.rglob("*.rst"):
        if "_templates" in path.parts:
            continue
        docnames.add(path.relative_to(SOURCE_DIR).with_suffix("").as_posix())
    return docnames


def parse_api_group_nav() -> tuple[list[dict[str, str]], dict[str, str]]:
    group_items: list[dict[str, str]] = []
    detail_to_group: dict[str, str] = {}
    if not API_ROOT_FILE.exists():
        return group_items, detail_to_group

    group_pattern = re.compile(r"- :doc:`([^`<]+)\s*<([^>]+)>`")
    detail_pattern = re.compile(r":doc:`[^`<]+ <([^>]+)>`")
    api_root_text = API_ROOT_FILE.read_text(encoding="utf-8")

    for line in api_root_text.splitlines():
        match = group_pattern.search(line.strip())
        if match is None:
            continue
        title = match.group(1).strip()
        target = match.group(2).strip()
        full_docname = target if "/" in target else f"en/dev/c/generated/{target}"
        group_items.append({"title": title, "docname": full_docname})

        group_file = SOURCE_DIR / f"{full_docname}.rst"
        if not group_file.exists():
            continue

        group_text = group_file.read_text(encoding="utf-8")
        for detail_doc in detail_pattern.findall(group_text):
            full_detail_doc = (
                detail_doc
                if "/" in detail_doc
                else f"en/dev/c/generated/{detail_doc}"
            )
            detail_to_group[full_detail_doc] = full_docname

    return group_items, detail_to_group


SOURCE_DOCNAMES = discover_source_docnames()
API_GROUP_ITEMS, API_DETAIL_TO_GROUP = parse_api_group_nav()


def resolve_language(docname: str) -> str | None:
    if docname.startswith("en/"):
        return "en"
    if docname.startswith("zh/"):
        return "zh"
    return None


def normalize_docname_for_nav(docname: str) -> str:
    if docname in API_DETAIL_TO_GROUP:
        return API_DETAIL_TO_GROUP[docname]
    if docname == "en/dev/c/generated/api_root":
        return "en/dev/c/index"
    if docname.startswith("en/dev/arch/") and docname != "en/dev/arch/index":
        return "en/dev/arch/index"
    if docname.startswith("zh/dev/arch/") and docname != "zh/dev/arch/index":
        return "zh/dev/arch/index"
    return docname


def build_api_nav_items(language: str) -> list[dict[str, Any]]:
    api_children: list[dict[str, Any]] = []

    for item in API_GROUP_ITEMS:
        localized_docname = item["docname"]
        nav_item: dict[str, Any] = {
            "title": item["title"],
            "docname": localized_docname,
            "children": [],
        }

        if language == "zh":
            localized_docname = localized_docname.replace("en/", "zh/", 1)
            nav_item["docname"] = localized_docname

            if localized_docname not in SOURCE_DOCNAMES:
                anchor = re.sub(r"[^a-z0-9]+", "-", item["title"].lower()).strip("-") or "api-group"
                nav_item["href_docname"] = "zh/dev/c/index"
                nav_item["href_anchor"] = anchor

        api_children.append(nav_item)

    return api_children


def build_nav_tree(language: str) -> list[dict[str, Any]]:
    titles = NAV_TITLES[language]
    api_children = build_api_nav_items(language)
    c_api_docname = f"{language}/dev/c/index"

    return [
        {
            "title": titles["basic"],
            "docname": f"{language}/basic/index",
            "children": [
                {"title": titles["overview"], "docname": f"{language}/basic/overview", "children": []},
                {"title": titles["install"], "docname": f"{language}/basic/install", "children": []},
                {"title": titles["quick_start"], "docname": f"{language}/basic/quick_start", "children": []},
            ],
        },
        {
            "title": titles["development"],
            "docname": f"{language}/dev/index",
            "children": [
                {"title": titles["architecture"], "docname": f"{language}/dev/arch/index", "children": []},
                {"title": titles["c_api"], "docname": c_api_docname, "children": api_children},
                {"title": titles["python_api"], "docname": f"{language}/dev/python/index", "children": []},
            ],
        },
        {
            "title": titles["faq"],
            "docname": f"{language}/faq/index",
            "children": [],
        },
    ]


def annotate_nav_tree(
    items: list[dict[str, Any]], current_docname: str
) -> tuple[list[dict[str, Any]], bool]:
    annotated_items: list[dict[str, Any]] = []
    subtree_active = False
    for item in items:
        children, child_active = annotate_nav_tree(item["children"], current_docname)
        is_current = item["docname"] == current_docname
        is_active = is_current or child_active
        annotated_items.append(
            {
                **item,
                "children": children,
                "current": is_current,
                "active": is_active,
                "expanded": is_active,
            }
        )
        subtree_active = subtree_active or is_active
    return annotated_items, subtree_active


def expand_first_level_nav(items: list[dict[str, Any]]) -> list[dict[str, Any]]:
    expanded_items: list[dict[str, Any]] = []
    for item in items:
        expanded_items.append(
            {
                **item,
                "expanded": bool(item["children"]),
            }
        )
    return expanded_items


def resolve_counterpart_docname(docname: str) -> str | None:
    if docname == "index":
        return None
    if docname == "zh/dev/c/index":
        return "en/dev/c/generated/api_root"
    if docname.startswith("en/dev/c/generated/"):
        return "zh/dev/c/index"
    if docname.startswith("en/"):
        candidate = f"zh/{docname[3:]}"
        return candidate if candidate in SOURCE_DOCNAMES else "zh/index"
    if docname.startswith("zh/"):
        candidate = f"en/{docname[3:]}"
        return candidate if candidate in SOURCE_DOCNAMES else "en/index"
    return None


def build_language_links(docname: str, language: str) -> list[dict[str, Any]]:
    counterpart = resolve_counterpart_docname(docname)
    if language == "en":
        return [
            {"label": LANGUAGE_LABELS["en"], "docname": docname, "current": True},
            {
                "label": LANGUAGE_LABELS["zh"],
                "docname": counterpart or "zh/index",
                "current": False,
            },
        ]
    if language == "zh":
        return [
            {
                "label": LANGUAGE_LABELS["en"],
                "docname": counterpart or "en/index",
                "current": False,
            },
            {"label": LANGUAGE_LABELS["zh"], "docname": docname, "current": True},
        ]
    return []


def add_axcl_page_context(app, pagename: str, templatename: str, context, doctree) -> None:
    del app, templatename, doctree
    language = resolve_language(pagename)
    context["axcl_is_root_landing"] = pagename == "index"
    context["axcl_current_language"] = language
    context["axcl_sidebar_home_doc"] = f"{language}/index" if language else "index"
    context["axcl_language_links"] = build_language_links(pagename, language) if language else []
    context["axcl_show_language_switch"] = bool(language)

    if language is None:
        context["axcl_nav_sections"] = []
        return

    normalized_docname = normalize_docname_for_nav(pagename)
    nav_sections, _ = annotate_nav_tree(build_nav_tree(language), normalized_docname)
    if pagename == "zh/index":
        nav_sections = expand_first_level_nav(nav_sections)
    context["axcl_nav_sections"] = nav_sections


def setup(app):
    app.connect("html-page-context", add_axcl_page_context)

    if extensions:
        def patch_generated_sources(_app, _env, _docnames):
            patch_exhale_function_signatures(API_ROOT_DIR, DOXYGEN_XML_DIR)

        app.connect("env-before-read-docs", patch_generated_sources)
