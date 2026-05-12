SPHINXBUILD ?= sphinx-build
SOURCEDIR = source
BUILDDIR = build

.PHONY: html clean

html:
	$(SPHINXBUILD) -b html "$(SOURCEDIR)" "$(BUILDDIR)/html"

clean:
	rm -rf "$(BUILDDIR)"
	find "$(SOURCEDIR)/en/dev/c/generated" -maxdepth 1 -type f -name '*.rst' -delete
	find "$(SOURCEDIR)/zh/dev/c/generated" -maxdepth 1 -type f -name '*.rst' -delete
