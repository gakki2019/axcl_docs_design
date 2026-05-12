# AXCL Docs Design

This repository contains the public AXCL documentation skeleton used for Read the Docs validation. It keeps public headers under `include/external`, generates the C/C++ API reference from Doxygen comments, and provides parallel English and Chinese Sphinx source trees.

## Repository Layout

```text
.
├── docs/
│   ├── requirements.txt
│   ├── Makefile
│   ├── source/
│   │   ├── conf.py
│   │   ├── en/
│   │   ├── zh/
│   │   ├── shared/
│   │   ├── _static/
│   │   └── _templates/
│   └── tools/
└── include/
	└── external/
```

## Local Build

Minimum host prerequisites follow `design/readthedocs_setup_sop.md`.

```bash
python3 -m venv .venv
. .venv/bin/activate
pip install -r docs/requirements.txt
make -C docs html
```

The generated site is written to `docs/build/html`.

## Notes

- The API reference is generated from headers in `include/external`.
- The English tree owns the generated API pages.
- The Chinese tree keeps explanatory navigation and links back to the English API reference.
- `docs/tools/sync_public_headers.sh` and `docs/tools/gen_api_index.py` are repository maintenance helpers.
