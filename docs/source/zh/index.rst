欢迎使用 AXCL 文档
==================

中文树用于验证双语导航、章节结构和 Read the Docs 版本切换；API 详细内容保持英文生成。

.. raw:: html

    <section class="axcl-hero axcl-hero-compact">
       <p class="axcl-eyebrow">中文导航入口</p>
       <p class="axcl-lead">突出安装、快速开始、开发文档与 API 入口，让双语站点更像正式产品文档，而不是占位目录。</p>
    </section>

目录
----

.. raw:: html

    <section class="axcl-card-grid">
       <a class="axcl-card" href="basic/overview.html">
          <span class="axcl-card-kicker">概览</span>
          <strong>产品与文档结构</strong>
          <span>快速了解仓库用途、读者对象和整体章节安排。</span>
       </a>
       <a class="axcl-card" href="basic/install.html">
          <span class="axcl-card-kicker">安装</span>
          <strong>环境准备</strong>
          <span>查看本地构建依赖、安装路径和最小准备步骤。</span>
       </a>
       <a class="axcl-card" href="basic/quick_start.html">
          <span class="axcl-card-kicker">上手</span>
          <strong>快速开始</strong>
          <span>从初始化到示例调用，走最短路径验证流程。</span>
       </a>
       <a class="axcl-card" href="dev/index.html">
          <span class="axcl-card-kicker">开发</span>
          <strong>开发指南</strong>
          <span>面向实现与维护，包含架构、接口与扩展入口。</span>
       </a>
       <a class="axcl-card" href="faq/index.html">
          <span class="axcl-card-kicker">支持</span>
          <strong>常见问题</strong>
          <span>收拢环境、构建和使用过程中的常见疑问。</span>
       </a>
       <a class="axcl-card" href="../en/dev/c/index.html">
          <span class="axcl-card-kicker">API</span>
          <strong>C/C++ 接口参考</strong>
          <span>详细 API 页保持英文生成，但从这里可以直接进入函数分组入口。</span>
       </a>
    </section>

.. toctree::
   :hidden:
   :maxdepth: 2

   basic/overview
   basic/install
   basic/quick_start
   dev/index
   faq/index

索引和搜索
----------

* :ref:`genindex`
* :ref:`search`
*** Add File: /home/jingxiaoping/github/axcl_docs_design/axcl_docs_design/docs/source/_static/css/custom.css
:root {
   --axcl-ink: #132238;
   --axcl-ink-soft: #41566f;
   --axcl-sky: #0b7fc2;
   --axcl-sky-deep: #085f92;
   --axcl-cyan: #2ec5d3;
   --axcl-amber: #ffb44d;
   --axcl-surface: #ffffff;
   --axcl-surface-alt: #f4f8fb;
   --axcl-border: rgba(19, 34, 56, 0.12);
   --axcl-shadow: 0 18px 40px rgba(11, 46, 77, 0.12);
}

.wy-side-nav-search,
.wy-nav-top {
   background: linear-gradient(135deg, #0a2942 0%, #0b7fc2 55%, #2ec5d3 100%);
}

.wy-side-nav-search > a,
.wy-nav-top a {
   font-weight: 700;
   letter-spacing: 0.02em;
}

.wy-menu-vertical a:hover,
.wy-menu-vertical a:focus,
.wy-menu-vertical li.current > a {
   color: var(--axcl-ink);
}

.wy-menu-vertical li.toctree-l1.current > a,
.wy-menu-vertical li.toctree-l2.current > a {
   border-left: 3px solid var(--axcl-cyan);
}

.wy-nav-content {
   max-width: 1180px;
   background:
      radial-gradient(circle at top right, rgba(46, 197, 211, 0.10), transparent 30%),
      linear-gradient(180deg, #fbfdff 0%, #f6f9fc 100%);
}

.rst-content h1,
.rst-content h2,
.rst-content h3 {
   color: var(--axcl-ink);
}

.rst-content a {
   color: var(--axcl-sky-deep);
}

.rst-content .section > p {
   color: var(--axcl-ink-soft);
}

.axcl-hero {
   margin: 1.25rem 0 2rem;
   padding: 1.5rem 1.5rem 1.4rem;
   border: 1px solid rgba(46, 197, 211, 0.28);
   border-radius: 20px;
   background:
      linear-gradient(135deg, rgba(11, 127, 194, 0.12), rgba(46, 197, 211, 0.06)),
      linear-gradient(180deg, #ffffff, #f7fbfe);
   box-shadow: var(--axcl-shadow);
}

.axcl-hero-compact {
   margin-top: 0.8rem;
}

.axcl-eyebrow {
   margin: 0 0 0.45rem;
   font-size: 0.78rem;
   font-weight: 700;
   letter-spacing: 0.14em;
   text-transform: uppercase;
   color: var(--axcl-sky-deep);
}

.axcl-lead {
   margin: 0;
   font-size: 1.08rem;
   line-height: 1.7;
   color: var(--axcl-ink);
}

.axcl-actions {
   display: flex;
   flex-wrap: wrap;
   gap: 0.85rem;
   margin-top: 1.25rem;
}

.axcl-button {
   display: inline-flex;
   align-items: center;
   justify-content: center;
   min-height: 42px;
   padding: 0.7rem 1rem;
   border: 1px solid rgba(11, 127, 194, 0.24);
   border-radius: 999px;
   background: rgba(255, 255, 255, 0.82);
   color: var(--axcl-ink) !important;
   font-weight: 700;
   text-decoration: none !important;
   transition: transform 120ms ease, box-shadow 120ms ease, border-color 120ms ease;
}

.axcl-button:hover,
.axcl-button:focus {
   transform: translateY(-1px);
   border-color: rgba(11, 127, 194, 0.45);
   box-shadow: 0 10px 24px rgba(11, 95, 146, 0.12);
}

.axcl-button-primary {
   background: linear-gradient(135deg, var(--axcl-sky-deep), var(--axcl-sky));
   color: #ffffff !important;
}

.axcl-card-grid {
   display: grid;
   grid-template-columns: repeat(auto-fit, minmax(220px, 1fr));
   gap: 1rem;
   margin: 1rem 0 1.6rem;
}

.axcl-card {
   display: flex;
   flex-direction: column;
   gap: 0.6rem;
   min-height: 186px;
   padding: 1.2rem;
   border: 1px solid var(--axcl-border);
   border-radius: 18px;
   background: linear-gradient(180deg, #ffffff, var(--axcl-surface-alt));
   box-shadow: 0 10px 28px rgba(19, 34, 56, 0.08);
   text-decoration: none !important;
   color: var(--axcl-ink) !important;
   transition: transform 120ms ease, box-shadow 120ms ease, border-color 120ms ease;
}

.axcl-card:hover,
.axcl-card:focus {
   transform: translateY(-2px);
   border-color: rgba(46, 197, 211, 0.45);
   box-shadow: 0 18px 34px rgba(11, 46, 77, 0.12);
}

.axcl-card strong {
   font-size: 1.05rem;
}

.axcl-card span {
   line-height: 1.6;
   color: var(--axcl-ink-soft);
}

.axcl-card-kicker {
   color: var(--axcl-sky-deep) !important;
   font-size: 0.78rem;
   font-weight: 700;
   letter-spacing: 0.08em;
   text-transform: uppercase;
}

.wy-breadcrumbs,
.rst-content code.literal,
.rst-content tt.literal {
   color: var(--axcl-ink);
}

@media (max-width: 768px) {
   .axcl-hero {
      padding: 1.1rem;
      border-radius: 16px;
   }

   .axcl-actions {
      flex-direction: column;
   }

   .axcl-button {
      width: 100%;
   }
}
*** Add File: /home/jingxiaoping/github/axcl_docs_design/axcl_docs_design/docs/source/_static/img/axcl-logo.svg
<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 320 72" role="img" aria-labelledby="title desc">
   <title id="title">AXCL Documentation</title>
   <desc id="desc">AXCL wordmark with geometric accents in blue and cyan.</desc>
   <defs>
      <linearGradient id="axclGradient" x1="0%" y1="0%" x2="100%" y2="100%">
         <stop offset="0%" stop-color="#0b7fc2"/>
         <stop offset="100%" stop-color="#2ec5d3"/>
      </linearGradient>
   </defs>
   <rect x="4" y="8" width="48" height="48" rx="14" fill="#0a2942"/>
   <path d="M18 44L28 20H36L46 44H39.5L37.4 38.6H26.5L24.3 44H18ZM28.8 33.6H35.1L31.9 25.2L28.8 33.6Z" fill="url(#axclGradient)"/>
   <path d="M64 22h12.6l7.1 9 7.2-9h12.4L90.1 37.5 104 54H91.4l-7.7-9.8-7.8 9.8H63.4l14-16.7L64 22Z" fill="#132238"/>
   <path d="M114.5 22h10.2c3.9 0 7 .7 9.4 2.2 2.7 1.7 4 4.3 4 7.8 0 2.3-.6 4.2-1.9 5.8-1.3 1.6-3.1 2.8-5.4 3.5L140 54h-11.8l-7.5-11h-1.1v11h-10.1V22Zm10.1 8v6.1h2.1c1.3 0 2.3-.3 3-.8.7-.5 1-1.3 1-2.2 0-1.1-.4-1.9-1.1-2.4-.7-.5-1.8-.8-3.3-.8h-1.7Z" fill="#132238"/>
   <path d="M147.7 22H158v24h15.1v8h-25.4V22Z" fill="#132238"/>
   <path d="M182 22h10.3v32H182V22Z" fill="#132238"/>
   <circle cx="282" cy="24" r="6" fill="#ffb44d"/>
   <path d="M214 54V22h9.7l13 16.7V22h10V54H237l-13-16.5V54h-10Z" fill="#132238"/>
   <path d="M258.5 54V22h28.8v7.6h-18.7v4.7h16.9v7.2h-16.9v4.8h19.2V54h-29.3Z" fill="#132238"/>
</svg>
