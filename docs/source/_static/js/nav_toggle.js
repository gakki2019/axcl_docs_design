document.addEventListener("DOMContentLoaded", () => {
    const nav = document.querySelector(".wy-menu-vertical");
    if (!nav) {
        return;
    }

    const match = window.location.pathname.match(/\/(en|zh)\//);
    const language = match ? match[1] : "default";
    const storageKey = `axcl-nav-expanded:${language}`;
    const transitionKey = "axcl-nav-pending-transition";
    const isLanguageHome = /\/(en|zh)\/index\.html$/.test(window.location.pathname);
    let skipNextPagehideSave = false;

    function getExpandableItems() {
        return Array.from(nav.querySelectorAll("li[aria-expanded][data-nav-id]"));
    }

    function loadState() {
        try {
            return JSON.parse(window.sessionStorage.getItem(storageKey) || "{}");
        } catch {
            return {};
        }
    }

    function syncExpandedState(item, expanded) {
        item.setAttribute("aria-expanded", expanded ? "true" : "false");
        item.classList.toggle("axcl-nav-open", expanded);
    }

    function saveState() {
        const state = {};
        getExpandableItems().forEach((item) => {
            state[item.dataset.navId] = item.getAttribute("aria-expanded") === "true";
        });
        window.sessionStorage.setItem(storageKey, JSON.stringify(state));
    }

    function applyState() {
        const state = loadState();
        getExpandableItems().forEach((item) => {
            const saved = state[item.dataset.navId];
            if (typeof saved === "boolean") {
                syncExpandedState(item, saved);
                return;
            }

            syncExpandedState(item, item.getAttribute("aria-expanded") === "true");
        });
    }

    function toggleItem(item) {
        const expanded = item.getAttribute("aria-expanded") === "true";
        syncExpandedState(item, !expanded);
        saveState();
    }

    function closestFromEventTarget(target, selector) {
        const element = target instanceof Element ? target : target?.parentElement;
        return element ? element.closest(selector) : null;
    }

    applyState();

    window.requestAnimationFrame(() => {
        document.documentElement.classList.add("axcl-nav-ready");
        document.documentElement.classList.remove("axcl-nav-transitioning");
    });

    nav.addEventListener("click", (event) => {
        const toggleButton = closestFromEventTarget(event.target, "button.toctree-expand");
        if (toggleButton) {
            event.preventDefault();
            event.stopPropagation();
            event.stopImmediatePropagation();

            const item = toggleButton.closest("li[aria-expanded]");
            if (!item) {
                return;
            }

            toggleItem(item);
            return;
        }

        const internalLink = closestFromEventTarget(event.target, "a.reference.internal");
        if (!internalLink) {
            return;
        }

        const branchLink = internalLink.closest("li[aria-expanded] > a.reference.internal");
        if (branchLink) {
            const item = branchLink.closest("li[aria-expanded]");
            const shouldToggleBranchLink = Boolean(
                item && (isLanguageHome || item.classList.contains("current"))
            );

            if (!shouldToggleBranchLink) {
                return;
            }

            event.preventDefault();
            event.stopPropagation();
            event.stopImmediatePropagation();

            if (!item) {
                return;
            }

            toggleItem(item);
            return;
        }

        if (event.metaKey || event.ctrlKey || event.shiftKey || event.altKey || event.button !== 0) {
            return;
        }

        saveState();
        skipNextPagehideSave = true;
        event.preventDefault();
        event.stopPropagation();
        event.stopImmediatePropagation();
        window.sessionStorage.setItem(transitionKey, "1");
        window.location.href = internalLink.href;
    }, true);

    window.addEventListener("pagehide", () => {
        if (skipNextPagehideSave) {
            skipNextPagehideSave = false;
            return;
        }

        saveState();
    });
});