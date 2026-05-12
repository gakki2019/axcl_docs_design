# AXCL Read the Docs 配置 SOP

## 目的

本文档说明如何准备开发环境、创建公开 GitHub 仓库 `axcl_docs_design`、上传所需文档文件、将仓库接入 Read the Docs，并发布按版本区分的 AXCL 文档。

版本管理模型参考 LightGBM 等项目：Read the Docs 从 Git 分支和 tag 构建不同版本的文档。

## 重要安全说明

不要在本文档、Git 仓库、Shell 脚本或命令历史示例中写入 SSH 密码、GitHub token、Read the Docs token 或其他凭证信息。

远程开发机可能通过 SSH 访问，但凭证不属于本 SOP 的内容。

本文默认 Git 和 VS Code 已可用，因此不在本 SOP 中检查。

## 目标仓库

仓库名称：

```text
axcl_docs_design
```

仓库可见性：

```text
public
```

主要托管平台：

```text
Read the Docs
```

## 所需账号与权限

1. 具有创建或管理 `axcl_docs_design` 权限的 GitHub 账号。
2. Read the Docs 账号。
3. 已将 Read the Docs 与 GitHub 账号关联。
4. 已授权 Read the Docs GitHub App 访问 `axcl_docs_design`。

## 开发机环境检查

在远程开发机上执行以下检查命令。这里有意排除了 Git 和 VS Code。

```bash
cat /etc/os-release
python3 --version
python3 -m venv --help
python3 -m pip --version
make --version
doxygen --version
dot -V
rsync --version
curl --version
```

如果没有 `curl`，但系统中有 `wget`，也可以接受：

```bash
wget --version
```

安装完 Python 文档依赖后，再检查 Sphinx：

```bash
sphinx-build --version
```

## 软件包安装

### Ubuntu 或 Debian

安装必需软件包：

```bash
sudo apt update
sudo apt install -y python3 python3-venv python3-pip make doxygen graphviz rsync curl ca-certificates tree
```

可选的本地编译工具：

```bash
sudo apt install -y build-essential
```

### CentOS、RHEL 或 Rocky Linux

安装必需软件包：

```bash
sudo dnf install -y python3 python3-pip make doxygen graphviz rsync curl ca-certificates tree
```

对于较老的系统，可用 `yum` 替代 `dnf`：

```bash
sudo yum install -y python3 python3-pip make doxygen graphviz rsync curl ca-certificates tree
```

如果在 RHEL 类系统上 `python3 -m venv` 不可用，可安装发行版提供的 venv 包，或者在用户空间安装 `virtualenv`。

Python 文档依赖应安装到项目虚拟环境中，而不是系统全局环境。

## 创建 GitHub 仓库

1. 在浏览器中打开 GitHub。
2. 创建一个新的公开仓库。
3. 仓库名设置为：

```text
axcl_docs_design
```

4. 选择公开可见。
5. 可选地初始化 `README.md`。
6. 将仓库克隆到远程开发机。

示例：

```bash
git clone <axcl_docs_design_repo_url>
cd axcl_docs_design
```

## 需要上传的目录结构

在 `axcl_docs_design` 仓库中创建如下结构：

```text
axcl_docs_design/
├── .gitignore
├── .readthedocs.yaml
├── README.md
├── docs/
│   ├── requirements.txt
│   ├── Makefile
│   ├── source/
│   │   ├── conf.py
│   │   ├── en/
│   │   │   ├── index.rst
│   │   │   ├── basic/
│   │   │   │   ├── overview.rst
│   │   │   │   ├── install.rst
│   │   │   │   └── quick_start.rst
│   │   │   ├── dev/
│   │   │   │   ├── index.rst
│   │   │   │   ├── arch/
│   │   │   │   │   ├── index.rst
│   │   │   │   │   ├── system.rst
│   │   │   │   │   └── device.rst
│   │   │   │   ├── c/
│   │   │   │   │   ├── index.rst
│   │   │   │   │   └── generated/
│   │   │   │   └── python/
│   │   │   │       └── index.rst
│   │   │   └── faq/
│   │   │       └── index.rst
│   │   ├── zh/
│   │   │   ├── index.rst
│   │   │   ├── basic/
│   │   │   │   ├── overview.rst
│   │   │   │   ├── install.rst
│   │   │   │   └── quick_start.rst
│   │   │   ├── dev/
│   │   │   │   ├── index.rst
│   │   │   │   ├── arch/
│   │   │   │   │   ├── index.rst
│   │   │   │   │   ├── system.rst
│   │   │   │   │   └── device.rst
│   │   │   │   ├── c/
│   │   │   │   │   ├── index.rst
│   │   │   │   │   └── generated/
│   │   │   │   └── python/
│   │   │   │       └── index.rst
│   │   │   └── faq/
│   │   │       └── index.rst
│   │   ├── shared/
│   │   │   ├── assets/
│   │   │   │   └── README.md
│   │   │   └── api/
│   │   │       └── README.md
│   │   ├── _static/
│   │   │   └── README.md
│   │   └── _templates/
│   │       └── README.md
│   └── tools/
│       ├── sync_public_headers.sh
│       ├── gen_api_index.py
│       └── README.md
└── include/
    └── external/
        └── ... copied AXCL public headers
```

## 必需文件

在将项目导入 Read the Docs 之前，至少应上传以下文件：

1. `.readthedocs.yaml`
2. `.gitignore`
3. `README.md`
4. `docs/requirements.txt`
5. `docs/source/conf.py`
6. `docs/source/en/index.rst`
7. `docs/source/zh/index.rst`
8. 至少一个英文内容页，例如 `docs/source/en/basic/overview.rst`
9. 至少一个中文内容页，例如 `docs/source/zh/basic/overview.rst`
10. `include/external/` 下的公开头文件

推荐首次上传时就包含目录结构中展示的全部骨架 RST 文件。

## 文件用途

| 文件或目录 | 用途 |
| --- | --- |
| `.readthedocs.yaml` | Read the Docs 构建配置。 |
| `.gitignore` | 排除本地环境文件和生成构建产物。 |
| `README.md` | 说明仓库用途和本地构建方式。 |
| `docs/requirements.txt` | Sphinx 文档构建所需的 Python 依赖。 |
| `docs/Makefile` | 本地构建入口。 |
| `docs/source/conf.py` | Sphinx 配置以及 Doxygen/Breathe/Exhale 集成配置。 |
| `docs/source/en` | 英文文档源码。 |
| `docs/source/zh` | 中文文档源码。 |
| `docs/source/shared/assets` | 共享图示和图片资源。 |
| `docs/source/_static` | 静态资源，例如 CSS 和 logo。 |
| `docs/source/_templates` | 可选的 Sphinx 模板覆盖目录。 |
| `docs/tools` | 同步、生成和检查脚本。 |
| `include/external` | 供 Doxygen 使用的公开头文件。 |

## `docs/tools` 的用途

`docs/tools` 用于维护者和 CI 辅助脚本，不属于面向用户的文档内容。

建议脚本包括：

1. `sync_public_headers.sh`
  - 将 AXCL SDK 仓库中的公开头文件同步到 `axcl_docs_design/include/external`。
  - 应在创建文档发布 tag 之前执行。
2. `gen_api_index.py`
  - 读取 Doxygen XML。
  - 按 `@defgroup` 分组生成以函数为中心的 API RST 页面。
  - 让结构体、枚举、typedef、宏和文件页不进入一级导航。
3. 后续检查项
  - 中英文目录树一致性。
  - 断链检查。
  - API 覆盖率检查。
  - 生成文件清理。

如果第一版尚未实现脚本，只提供 `docs/tools/README.md` 也可以完成首次仓库上传。

## `.gitignore` 示例

```gitignore
.venv/
__pycache__/
*.pyc
docs/build/
docs/source/shared/api/generated/
docs/source/en/dev/c/generated/
docs/source/zh/dev/c/generated/
_doxygen/
doxygen/xml/
```

## `.readthedocs.yaml` 示例

```yaml
version: 2

build:
  os: ubuntu-24.04
  tools:
    python: "3.12"
  apt_packages:
    - doxygen
    - graphviz

sphinx:
  configuration: docs/source/conf.py
  builder: html
  fail_on_warning: false

python:
  install:
    - requirements: docs/requirements.txt
```

## `docs/requirements.txt` 示例

```text
sphinx
breathe
exhale
sphinx-rtd-theme
myst-parser
```

在第一版 PoC 稳定后，应固定具体版本号。

## 本地构建命令示例

在 `axcl_docs_design` 仓库根目录执行：

```bash
python3 -m venv .venv
source .venv/bin/activate
python3 -m pip install --upgrade pip
python3 -m pip install -r docs/requirements.txt
sphinx-build -b html docs/source docs/build/html
```

生成的 HTML 首页位于：

```text
docs/build/html/index.html
```

如果已经提供 `docs/Makefile`，也可以执行：

```bash
make -C docs html
```

## 复制公开头文件

将 AXCL SDK 仓库中的公开头文件复制到文档仓库中：

```text
from: axcl/include/external/
to:   axcl_docs_design/include/external/
```

如果两个仓库在同一台机器上，可使用 `rsync`：

```bash
rsync -av --delete /path/to/axcl/include/external/ /path/to/axcl_docs_design/include/external/
```

只能复制公开头文件。

## 提交初始仓库内容

在 `axcl_docs_design` 仓库根目录执行：

```bash
git status
git add .
git commit -m "Initialize AXCL documentation design"
git push origin main
```

## 将项目导入 Read the Docs

1. 登录 Read the Docs。
2. 将 Read the Docs 账号与 GitHub 账号关联。
3. 如果系统提示，安装或授权 Read the Docs GitHub App。
4. 进入 Read the Docs 控制台。
5. 点击 Add project。
6. 选择 `axcl_docs_design`。
7. 确认仓库元信息。
8. 确认仓库根目录存在 `.readthedocs.yaml`。
9. 完成项目创建。
10. 触发首次构建。

首次构建应从默认分支生成 `latest` 文档。

## 在 Read the Docs 中配置版本

Read the Docs 版本来源于 Git 分支和 tag。

建议策略如下：

1. 默认分支构建 `latest`。
2. SDK 发布 tag 构建对应版本文档，例如 `v1.2.3`。
3. `stable` 指向最新稳定发布。
4. `axcl_docs_design` 中的 tag 应与 AXCL SDK 发布 tag 保持一致。

发布 tag 推送后，进入 Read the Docs 的 Versions 页面检查。如果该 tag 没有自动激活，需要手动激活。

## 发布一个文档版本

1. 先同步与本次 SDK 发布匹配的公开头文件：

```bash
rsync -av --delete /path/to/axcl/include/external/ /path/to/axcl_docs_design/include/external/
```

2. 更新文档内容。
3. 执行本地构建。
4. 提交修改。
5. 创建与 SDK 版本一致的 tag：

```bash
git tag v1.2.3
git push origin main
git push origin v1.2.3
```

6. 打开 Read the Docs 的 Versions 页面。
7. 如有需要，激活 `v1.2.3`。
8. 确认版本 flyout 中正确显示 `latest`、`stable` 和 `v1.2.3`。

## 故障排查

### 找不到 Doxygen

先检查本地安装：

```bash
doxygen --version
```

再检查 `.readthedocs.yaml` 是否包含：

```yaml
build:
  apt_packages:
    - doxygen
```

### 找不到 Graphviz

先检查本地安装：

```bash
dot -V
```

如果启用了图示功能，确认 `.readthedocs.yaml` 中包含 `graphviz`。

### Breathe 无法找到 Doxygen XML

检查 Doxygen XML 是否已生成，并确认 `docs/source/conf.py` 中的 `breathe_projects` 指向了正确的 XML 目录。

### Read the Docs 版本不可见

1. 确认 tag 已推送到 GitHub。
2. 检查 Read the Docs 的 Versions 页面。
3. 如果版本处于 inactive 状态，手动激活。
4. 检查该版本是否被隐藏。

### API 内容与 SDK 发布不匹配

检查 `axcl_docs_design` 中的 `include/external` 是否在打 tag 之前同步自对应的 AXCL SDK 发布版本。

### 误复制了私有头文件

提交前将其移除。`axcl_docs_design` 是公开仓库，只能包含公开头文件和公开文档。

## 最终检查清单

在要求 Read the Docs 构建发布版本之前，确认以下条件成立：

1. `axcl_docs_design` is public.
2. `.readthedocs.yaml` exists at repository root.
3. `docs/requirements.txt` exists.
4. `docs/source/conf.py` exists.
5. 中英文首页都已存在。
6. `include/external` 中包含正确版本的公开头文件。
7. 本地 Sphinx 构建成功。
8. 没有将生成的 HTML、Doxygen XML 或 `.venv` 目录提交到仓库。
9. 发布 tag 与 AXCL SDK 版本一致。
