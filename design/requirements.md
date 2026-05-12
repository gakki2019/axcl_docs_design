# AXCL 文档需求

## 背景

AXCL SDK 需要面向用户和开发者提供一套可按版本区分的 HTML 文档站点。当前需求聚焦于文档框架设计：除基于公开 C/C++ API 注释自动生成的 API 参考文档外，其余内容均以自动生成的基础演示内容为主，用于验证目录、导航、版本、语言切换和 API 集成链路。

公开 API 头文件从 `include/external` 导出。API 注释采用 Doxygen 风格标注，并作为生成 C/C++ API 参考文档的唯一可信来源。

## 目标

1. 使用 Sphinx 生成 HTML 文档。
2. 基于 `include/external` 中的 Doxygen 注释生成 C/C++ API 参考文档。
3. 使用 Breathe 和 Exhale，或者使用 Breathe 加一层轻量生成脚本，将 Doxygen XML 集成到 Sphinx。
4. 使用名为 `axcl_docs_design` 的公开 GitHub 仓库，并托管到 Read the Docs。
5. 采用类似 LightGBM 的 Read the Docs 版本管理方式，让用户可选择 `latest`、`stable` 以及各个 SDK 发布版本。参考资料：LightGBM 文档源码 `https://github.com/lightgbm-org/LightGBM/tree/master/docs`，在线文档 `https://lightgbm.readthedocs.io/en/latest/`。
6. 支持英文和中文两套文档导航。
7. API 符号说明仅保留英文。Doxygen 自动生成的 API 内容不属于翻译范畴；中文页面只覆盖外围说明性文字和章节描述。
8. 第一阶段仅保留 Python API 文档占位页。

## 非目标

1. 第一阶段不生成 Python API 参考文档。
2. 不将 C/C++ API 注释翻译成中文。
3. 在 Read the Docs 已可满足需求的前提下，不自研版本选择器。
4. 不在公开文档仓库中发布内部或私有 SDK 头文件。

## 文档范围

第一阶段文档范围包括：

说明：本需求属于文档框架设计。除 Doxygen 生成的 API 文档外，其余页面均为自动生成的基础演示内容，用于验证整体框架可行性，而不是交付正式文案。

1. 基础文档
   - 概览
   - 安装指南
   - 快速开始
2. 开发文档
   - 架构
   - C/C++ API
   - Python API 占位页
3. FAQ
4. 基于 `include/external` 生成的公开 API 参考文档

面向用户的可见一级导航应固定为“基础文档 / 开发文档 / FAQ”。根 landing page 可以作为站点入口存在，但不应把语言目录本身作为一级导航项展示。

## 仓库要求

文档将托管在以下公开 GitHub 仓库中：

```text
axcl_docs_design
```

该仓库必须同时包含 Sphinx 文档源码，以及供 Doxygen 扫描所需的公开 API 头文件。

公开头文件应放置在：

```text
include/external/
```

该布局与 AXCL 仓库结构保持一致，并且可让 Doxygen 输入路径保持清晰明确。

## 版本管理要求

版本管理应遵循 Read the Docs 的标准模式，参考 LightGBM 等项目：

1. 默认分支构建 `latest` 文档。
2. SDK 发布文档通过 `axcl_docs_design` 中的 Git tag 构建。
3. 发布 tag 应与 AXCL SDK 发布 tag 对齐，例如 `v1.2.3`。
4. `stable` 应指向最新稳定 SDK 文档版本，可由 Read the Docs 自动推断或通过项目配置显式指定。
5. 用户通过 Read the Docs 的版本切换 flyout 选择版本。

每个文档 tag 中都必须包含与之匹配版本的 `include/external` 公开头文件。

## 语言要求

文档源码应采用平行的中英文目录树：

```text
docs/source/en/
docs/source/zh/
```

两套目录树应保持结构对齐，以便统一处理导航、语言切换以及缺页检查。

语言切换应作为页内入口呈现，而不是将 `en` 和 `zh` 作为 sidebar 的一级导航节点直接暴露给用户。

用户在任意英文或中文页面中，都应看到当前语言独占的导航树；切换语言时，应优先跳转到结构对齐的对应页面，而不是退回另一语言首页。

C/C++ API 参考文档内容由公开 API 注释自动生成，因此保持英文。该部分属于 Doxygen 自动产物，不在翻译范围内。中文页面可以在 API 参考页外围补充中文引导说明。

## API 生成要求

API 生成链路为：

```text
include/external/*.h
    -> Doxygen XML
    -> Breathe/Exhale integration
    -> Sphinx HTML
```

Doxygen 配置应只扫描 `include/external` 下的公开 API 头文件。

## API 展示要求

可见 API 入口应以函数为中心：

1. 用户通过函数列表进入 API 文档。
2. 函数按头文件中的 Doxygen `@defgroup` 和 `@ingroup` 分组展示。
3. 结构体、枚举、typedef、宏以及头文件页不应作为一级导航入口。
4. 结构体、枚举、typedef 和宏仍可保留详情页或锚点，以便函数签名、参数说明以及 `@ref` 链接跳转到对应定义。
5. 头文件页不应暴露为面向用户的导航入口。
6. Sidebar 中 `C/C++ API` 的可见层级应止于 API group 页面，例如 `system`、`context`、`control`；函数详情页不应出现在可展开的导航树中。

如果 Exhale 默认生成的 `library_root` 页面会展示文件层级、类/结构体层级或完整符号索引，并与“以函数为入口”的要求冲突，则不应将其作为对外 API 首页。

## API 分组要求

API 分类由头文件注释定义，而不是额外人工维护一套独立分类树。

Runtime 和 Native 仅是示例，不是固定分类。最终 API 分类应遵循头文件中整理后的 Doxygen group 定义。

每个公开 API 函数都应归属于一个合法的 Doxygen group。

## API 注释要求

公开 API 注释应采用统一的 Doxygen 风格：

1. 公开函数、结构体、枚举、typedef 和宏都应具备 `@brief`。
2. 函数参数应使用 `@param[in]`、`@param[out]` 或 `@param[in,out]`。
3. 错误码返回应使用 `@retval`。
4. 示例应使用 `@par Example` 以及 `@code{.c}` / `@endcode`。
5. 交叉引用应使用 `@ref`。
6. API 分组应使用 `@defgroup` 和 `@ingroup`。

## 第一阶段交付物

第一阶段应提供：

1. `requirements.md`：本需求文档。
2. `design.md`：文档架构技术设计。
3. `readthedocs_setup_sop.md`：环境准备与 Read the Docs 配置 SOP。
4. `axcl_docs_design` 仓库初始布局方案。
5. 中英文 Sphinx 文档骨架文件。
6. Doxygen/Breathe/Exhale 配置方案。
7. 以函数为入口的 API 页面生成方案。

## 验收标准

1. 需求、设计和 SOP 文档已放置在 AXCL 仓库的 `docs/design` 目录下。
2. 提议的 `axcl_docs_design` 仓库结构明确，且可以直接上传到 GitHub。
3. SOP 说明了远程开发机所需安装的软件包，并明确排除了 Git 和 VS Code 检查。
4. SOP 说明了 Read the Docs 项目导入和版本发布流程。
5. 设计文档明确说明 API 文档以函数为入口，而不是以文件或类型索引为入口。
6. 设计文档明确说明在文档仓库中，Doxygen 输入路径为 `include/external`。
7. 需求或设计文档明确说明语言切换使用页内入口，而不是将语言目录暴露为 sidebar 一级导航。
8. 需求或设计文档明确说明任意页面只渲染当前语言的导航树，并尽量跳转到另一语言的对应页面。
9. 需求或设计文档明确说明 `C/C++ API` 在 sidebar 中只展开到 API group 页面，而不展开函数详情页。
