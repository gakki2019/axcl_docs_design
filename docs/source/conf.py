from __future__ import annotations

import importlib.util
import shutil
import subprocess
from pathlib import Path

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
html_theme_options = {
    "collapse_navigation": False,
    "sticky_navigation": True,
    "navigation_depth": 4,
    "includehidden": True,
    "titles_only": False,
}
html_title = project
master_doc = "index"


def setup(app):
    if not extensions:
        return

    def patch_generated_sources(_app, _env, _docnames):
        patch_exhale_function_signatures(API_ROOT_DIR, DOXYGEN_XML_DIR)

    app.connect("env-before-read-docs", patch_generated_sources)
