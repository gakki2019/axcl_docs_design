# AXCL 文档设计

## 概述

AXCL 文档将构建为基于 Sphinx 的 HTML 站点，并通过名为 `axcl_docs_design` 的公开 GitHub 仓库托管到 Read the Docs。

本设计遵循以下原则：

1. 文档仓库布局尽量贴近 AXCL SDK 仓库布局。
2. 使用 Read the Docs 进行版本管理，而不是维护自定义版本选择器。
3. 使用公开头文件中的 Doxygen 注释作为 C/C++ API 参考文档的唯一可信来源。
4. API 参考文档以函数作为用户的主要入口。
5. 中英文内容目录保持平行。
6. 生成产物尽量不提交到 Git。

## 架构

```text
AXCL SDK public headers
    axcl/include/external/
        |
        | sync before docs release
        v
axcl_docs_design public GitHub repo
    include/external/
    docs/source/
        |
        | Read the Docs build
        v
Doxygen XML -> Breathe/Exhale -> Sphinx HTML -> Read the Docs hosted site
```

## GitHub 仓库

仓库名称：

```text
axcl_docs_design
```

可见性：

```text
public
```

该仓库之所以设为公开，是因为计划使用 Read the Docs Community 托管，并且其中只包含公开文档源码和公开 API 头文件。

## 仓库结构

初始仓库结构应为：

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
│   │   │   │   ├── index.rst
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
│   │   │   │   ├── index.rst
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
        ├── axcl.h
        ├── axcl_rt.h
        ├── axcl_rt_device.h
        ├── axcl_rt_context.h
        ├── axcl_rt_stream.h
        ├── axcl_rt_memory.h
        ├── axcl_rt_engine.h
        ├── axcl_rt_event.h
        ├── axcl_rt_type.h
        └── ... copied public headers
```

## 目录用途

| 路径 | 用途 |
| --- | --- |
| `.readthedocs.yaml` | Read the Docs 构建配置。 |
| `docs/requirements.txt` | 构建文档所需的 Python 依赖。 |
| `docs/Makefile` | 本地构建命令入口。 |
| `docs/source/conf.py` | Sphinx 配置文件。 |
| `docs/source/en` | 英文人工编写文档。 |
| `docs/source/zh` | 中文人工编写文档。 |
| `docs/source/shared/assets` | 共享图片、SVG、图示以及复用素材。 |
| `docs/source/_static` | Sphinx 静态资源，例如 logo、CSS 或少量 JS。 |
| `docs/source/_templates` | 可选的 Sphinx 模板覆盖目录。 |
| `docs/tools` | 文档维护和生成辅助脚本。 |
| `include/external` | 从 AXCL SDK 同步过来的公开 API 头文件，作为 Doxygen 输入。 |

## `docs/tools` 的职责

`docs/tools` 面向维护者自动化，不属于用户可见文档内容。

规划中的工具包括：

1. `sync_public_headers.sh`
    - 将 AXCL SDK 仓库中的公开头文件同步到 `axcl_docs_design/include/external`。
    - 避免发布过程中的手工复制漂移。
    - 应在创建文档发布 tag 之前执行。
2. `gen_api_index.py`
    - 读取 Doxygen XML。
    - 按 `@defgroup` / `@ingroup` 对函数分组。
    - 生成只包含函数入口的 RST API 页面。
    - 让结构体、枚举、typedef、宏和文件页不进入一级导航。
3. 后续可选检查项
    - 中英文目录树一致性检查。
    - API 覆盖率检查。
    - 链接检查封装。
    - 生成文件清理。

第一版实现可以先仅提供 `docs/tools/README.md`。实际脚本可在 API 生成 PoC 阶段补充。

## Sphinx 布局

中英文源码树保持平行：

```text
docs/source/en/
docs/source/zh/
```

每种语言都采用相同的章节布局：

```text
index.rst
basic/
    index.rst
    overview.rst
    install.rst
    quick_start.rst
dev/
    index.rst
    arch/
        index.rst
        system.rst
        device.rst
    c/
        index.rst
        generated/
    python/
        index.rst
faq/
    index.rst
```

## 导航模型

顶层导航应为：

1. 基础文档
    - 概览
    - 安装指南
    - 快速开始
2. 开发文档
    - 架构
   - C/C++ API
   - Python API
3. FAQ

第一阶段中，Python API 页面仅作为占位页存在。

站点根 landing page 可作为中英文总入口，但不应把 `en` 和 `zh` 目录本身作为 sidebar 一级导航项暴露给用户。实际可见导航应由当前语言页的目录树驱动。

任意英文或中文页面都应只渲染当前语言的 sidebar 导航树。语言切换应以内嵌页内入口呈现，并优先跳转到结构对齐的对应页面；若某个自动生成的 API 详情页不存在中文对应页面，则中文入口应回退到中文 API 包装页或对应英文 API 入口页。

`C/C++ API` 在 sidebar 中只应展开到 API group 页面，例如 `system`、`context`、`control`；函数详情页仍然存在，但不作为可见导航树的一部分。

## 语言切换与导航渲染

建议采用单一 Sphinx 工程中的平行语言目录，并通过页面上下文和模板覆盖控制导航展示，而不是把两棵语言树同时挂在根 sidebar 下。

推荐策略如下：

1. 根 `index.rst` 作为站点 landing page，仅提供品牌入口和跳转，不承担双语 sidebar 根的职责。
2. `docs/source/en/index.rst` 与 `docs/source/zh/index.rst` 分别作为英文和中文的实际导航根。
3. `conf.py` 根据当前 `docname` 计算当前语言、对应语言页面，以及 sidebar 应使用的语言根文档。
4. 通过 `_templates` 覆盖 `sphinx_rtd_theme` 的布局或 sidebar 局部模板，使页面只渲染当前语言树，并在页内输出轻量语言切换入口。
5. 对自动生成的 API 详情页保留英文原文；中文侧通过包装页提供说明和跳转，而不复制 API 符号内容。

## C/C++ API 生成

API 生成流水线为：

```text
include/external/*.h
    -> Doxygen XML
    -> Breathe/Exhale symbol rendering
    -> generated function-oriented RST entry pages
    -> Sphinx HTML
```

文档仓库中的 Doxygen 输入路径为：

```text
include/external
```

生成的 XML 应放在构建目录中，例如：

```text
docs/build/doxygen/xml
```

生成的 RST 可以放在一个被 Git 忽略的生成目录下，或者在足够稳定后由 Sphinx 构建过程动态生成。

## API 展示设计

不使用 Exhale 默认根页面作为对外 API 入口，因为该页面可能暴露文件层级、类/结构体层级或完整 API 索引。

对外可见的 API 入口应由自定义生成或人工整理：

```text
C/C++ API
    Device API
        axclrtSetDevice
        axclrtResetDevice
        axclrtGetDevice
        ...
    Context API
        ...
    Memory API
        ...
```

可见入口只列出函数。

结构体、枚举、typedef、宏以及文件页不应出现在一级导航中。但它们仍可作为链接目标存在，以便用户从函数签名、参数说明和 `@ref` 引用跳转到相关定义。

面向用户的 sidebar 中，`C/C++ API` 的展开深度控制在 group 页面层级。group 页面负责列出函数入口，Exhale/Breathe 生成的函数详情页只作为内容页和跳转目标存在。

## API 分类

API 分类遵循头文件中的 Doxygen group：

1. `@defgroup` defines a group.
2. `@ingroup` assigns an API symbol to a group.
3. 生成的 API 函数入口页按这些定义对函数进行分组。

Runtime 和 Native 只是示例，并不是本设计中的固定分类。

## 建议的 Sphinx 配置点

关键的 Sphinx/Breathe/Exhale 配置如下：

```python
extensions = [
    "breathe",
    "exhale",
]

breathe_projects = {
    "AXCL": "../build/doxygen/xml",
}
breathe_default_project = "AXCL"
breathe_domain_by_extension = {
    "h": "c",
}
breathe_show_include = False
```

如果使用 Exhale 生成符号详情页，应避免将其默认 `library_root` 暴露为用户可见的 API 首页。更推荐基于 Doxygen XML 自定义生成函数入口页。

## Read the Docs 配置

文档仓库根目录应包含 `.readthedocs.yaml`。

初始配置示例如下：

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

## Python 依赖

初始 `docs/requirements.txt` 如下：

```text
sphinx
breathe
exhale
sphinx-rtd-theme
myst-parser
```

PoC 稳定后，应对版本进行固定，以保证 Read the Docs 构建可复现。

## 版本管理

Read the Docs 的版本对应 Git 分支和 tag。

1. 默认分支构建 `latest`。
2. 发布 tag `vX.Y.Z` 构建 `vX.Y.Z` 文档版本。
3. `stable` 应指向最新稳定 SDK 文档。
4. `axcl_docs_design` 中的文档 tag 应与 AXCL SDK 发布 tag 保持一致。

由于 `axcl_docs_design` 是公开仓库，因此每个 SDK 版本对应的公开头文件都必须在创建文档发布 tag 之前提交到仓库中。

## 头文件同步

在 `axcl_docs_design` 中创建发布 tag 之前，应同步 AXCL 公开头文件：

```text
from: axcl/include/external/
to:   axcl_docs_design/include/external/
```

只允许复制公开头文件，内部头文件不得发布。

## 构建产物

以下生成产物不应提交：

1. Sphinx HTML output.
2. Doxygen XML.
3. Exhale 生成的临时文件，除非 PoC 证明它们必须纳入版本控制。
4. Python 虚拟环境。
5. Python 缓存目录。

## 待确认项

1. 确认最终 Read the Docs 项目 slug。它可能会将 `axcl_docs_design` 规范化为 `axcl-docs-design`。
2. 在 API 渲染 PoC 完成后，确认第一阶段是否必须实现 `gen_api_index.py`。
3. 如需更接近 ESP-IDF 的体验，确认语言切换入口放在正文标题区还是页面工具栏区；两者都可由模板覆盖实现。

## 验证方式

当满足以下条件时，可认为本设计有效：

1. Local Sphinx build succeeds.
2. Doxygen XML is generated from `include/external`.
3. API 入口页能够按 Doxygen group 维度展示函数。
4. 结构体、枚举、typedef、宏以及文件页不会作为一级导航入口出现。
5. Read the Docs 能成功构建 `latest`。
6. Read the Docs 能成功构建并展示诸如 `v1.0.0` 的发布 tag。
7. 任意英文或中文内容页只显示当前语言的 sidebar 导航树。
8. 页面内存在语言切换入口，并能优先跳转到对应语言的对齐页面。
9. `C/C++ API` 在 sidebar 中只展开到 API group 页面，而不是函数详情页。
