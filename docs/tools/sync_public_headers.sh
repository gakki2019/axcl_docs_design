#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 1 ]]; then
    echo "usage: $0 <source-external-include-dir>" >&2
    exit 1
fi

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
src_dir="$1"
dst_dir="$repo_root/include/external"

if [[ ! -d "$src_dir" ]]; then
    echo "source directory not found: $src_dir" >&2
    exit 1
fi

mkdir -p "$dst_dir"
rsync -av --delete --include='*.h' --exclude='*' "$src_dir"/ "$dst_dir"/
