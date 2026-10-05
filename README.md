# cpp_practise

C++ 练习仓库 —— 记录从零开始学 C++ 的每一次课后小练。

- 教材：[C++学习网 studycpp.cn](https://www.studycpp.cn/)（[learncpp.com](https://www.learncpp.com/) 中文译站，28 章，每节带练习）
- 用法：**每节示例都必须手敲并改动一处**，只看不敲不算学完
- 长期目标：为 2027 年游戏客户端实习（C++ / UE5）打底；规划文档在 `D:\career_plan\docs\实习规划\`

---

## 环境

| 项 | 值 |
| --- | --- |
| IDE | Visual Studio Community 2026（安装在 `D:\MVcode`） |
| 编译器 | MSVC 14.51（`PlatformToolset` = `v145`） |
| Windows SDK | 10.0.26100.0（`D:\Windows Kits\10`） |
| C++ 标准 | C++20（`LanguageStandard` = `stdcpp20`） |
| 目标平台 | x64（工程同时保留 Win32 配置） |
| Git | 2.55.0.windows.3 |

---

## 目录结构

```
cpp_practise/
├── README.md
├── .gitignore
├── Directory.Build.props                  ← 全仓库编译选项：让 MSVC 按 UTF-8 读源码（见「源文件编码」）
├── Project1_stdcout_sin_endl/             小练 01：输入输出
│   └── FileName.cpp                       源码：读入两个整数并回显（另有 .slnx / .vcxproj 等工程文件）
├── Project2_2倍输出输入值/                  站内 1.10 练习：输入整数 → 输出 2 倍
│   └── 1.10.cpp
├── 1.8自测/                                站内 1.8 自测：字面值与操作符
│   └── 1.8practise.cpp
└── 10.4交付任务/                           10/4 交付：BMI 计算（1.10 自己设计的程序）
    └── main.cpp
```

> `.vs/`、`x64/`、`Project1.e7d0550b/`（编译中间件）都是本机构建产物，已被 `.gitignore` 排除，不会进仓库。
> 如果以后 VS 又生成了新的中间目录，把它加进 `.gitignore` 即可。

---

## 怎么构建和运行

### 在 Visual Studio 里

1. 双击 `Project1_stdcout_sin_endl\Project1_stdcout_sin_endl.slnx`
2. 按 **F5**（调试运行）或 **Ctrl+F5**（不调试直接运行）
3. 控制台出现 `Enter two numbers separated by a space:`，输入形如 `3 5` 后回车

### 命令行（Developer PowerShell for VS 2026）

```powershell
cd "D:\cpp_practise\Project1_stdcout_sin_endl"
msbuild Project1_stdcout_sin_endl.vcxproj /p:Configuration=Debug /p:Platform=x64
.\x64\Debug\Project1_stdcout_sin_endl.exe
```

只编译单个文件也可以（不进 VS）：

```powershell
cl /nologo /EHsc /std:c++20 FileName.cpp
.\FileName.exe
```

> ⚠️ **这条绕过 MSBuild，所以 `Directory.Build.props` 里的 `/source-charset:utf-8` 不会生效。**
> 手打 `cl` 时要么源码**带 BOM**，要么自己补上选项：`cl /nologo /EHsc /std:c++20 /source-charset:utf-8 FileName.cpp`

---

## 练习记录

| 日期 | 编号 | 文件 | 内容 | 知识点 |
| --- | --- | --- | --- | --- |
| 2026-10-03 | 小练 01 | `Project1_stdcout_sin_endl/FileName.cpp` | `std::cout` 打印提示 → `std::cin` 读入两个 `int` → 回显 | `#include <iostream>`、`std::cout` / `std::cin`、`int x{ }` 值初始化 |

> 计划中的后续安排见 `D:\career_plan\docs\实习规划\游戏主线_十月逐日计划.md`（第 1 章 → 函数 → 引用与指针 → class）。

---

## 已知待改（自己动手改，别直接复制）

- `FileName.cpp` 回显那一行少了空格：`<< "and" <<` 会输出 `You entered 3and5`，应补成 `" and "`
- 该文件没有写 `return 0;`：`main` 会隐式返回 0、编译器不报错，但显式写出来更清楚
- `int x{ };` 是**值初始化**（结果为 0），不是「未初始化」；想复现未定义行为要写 `int x;`
- 变量名 `x` / `y` 可读性差：等学完命名规则（studycpp 1.6）后改成 `first_number` / `second_number`

---

## 源文件编码（踩过坑，别再踩）

**两道防线，各管一段：**
① **仓库根的 `Directory.Build.props`**（2026-10-05 已装）让 MSVC **按 UTF-8 读源码** —— 无 BOM 也行，本目录及其子目录下**所有工程（含以后新建的）自动生效**，用 VS 或 `msbuild` 构建都算。
② 仍然建议把**带中文的** `*.cpp` / `*.h` 存成 **「UTF-8 带签名」（UTF-8 with BOM）** —— 它管住 ① 管不到的场合（见下）。

- **为什么**：无 BOM 的 UTF-8 + 中文 → MSVC 会按**系统代码页 936/GBK** 解释源文件；中文的 UTF-8 尾字节会和紧跟的引号拼成一个 GBK 双字节字，**把闭合引号吃掉** → `warning C4819` + `error C2001: 字符串字面量中的换行符`（连带 `error C2143`）。编译直接失败，而不是中文乱码那么"温柔"。
- **实例**：`10.4交付任务\main.cpp` 就是这么挂的（2026-10-05，提交 `2198baa` 修复）。同一份代码只加 3 字节 BOM 后，`cl /nologo /EHsc /std:c++20` 零警告零错误。
- **VS 里怎么存**：文件 → **高级保存选项**（或「另存为」时点保存按钮旁的**下拉箭头 → 编码保存**）→ 编码选 **「UTF-8 带签名」**。不同 VS 版本/模板的默认值不一样，**别赌默认**。
- **本项目实际怎么设**：`Directory.Build.props` 给所有工程注入 **`/source-charset:utf-8 /we4828`**。
  - **只用 `source-charset`，不用 `/utf-8`**：`/utf-8` 会把**执行字符集**也设成 UTF-8，默认 936 的 cmd 窗口里中文会变乱码；只设 source-charset，窄字符串按 GBK 落地，控制台直接正常显示。
  - **`/we4828` 是报警器**：源文件里有"非法 UTF-8 字节"（多半是从别处拷来的 GBK 文件）时**直接编译失败**，而不是悄悄乱码。
  - **⚠️ 它管不到的三种场合（靠防线②兜）**：裸命令行 `cl …`（绕过 MSBuild）／**本仓库之外**的工程（如 `D:\cpp learning`、将来的 `D:\cpp_snake`）／CMake、gcc、clang 等其他构建链。
- **反向规则**：`.md` / `.json` / `.py` / `.mjs` 这类跨平台文件**不要带 BOM**（Node / Python / `JSON.parse` 会把 BOM 当正文字符，容易报错）。
### 遇到这些编号 = 编码问题

| 编号 | 含义 | 怎么办 |
|---|---|---|
| `warning C4819` | 文件里有字节不能在当前代码页(936)中表示 | MSVC 正按 GBK 读你的 UTF-8 文件 → 存 BOM，或确认 `/source-charset:utf-8` 生效了 |
| `error C2001` | 字符串字面量中的换行符 | 中文出现在**字符串**里时的典型后果（闭合引号被 GBK 双字节吃掉）→ 同上 |
| `error C2143` | 缺少 `;` | 通常是 C2001 的连带 → **别去加分号，先修编码** |
| `error C4828` | 文件在当前源字符集(65001)中有非法字符 | 文件其实**不是 UTF-8**（多半是 GBK）→ 转成 UTF-8；本仓库已用 `/we4828` 把它升级为错误 |

- **自查前 3 字节**：
  ```powershell
  $b = [IO.File]::ReadAllBytes('10.4交付任务\main.cpp')
  ($b[0..2] | ForEach-Object { $_.ToString('x2') }) -join ' '   # ef bb bf = 有 BOM
  ```

---

## 提交约定

- 每学完一节、每天至少一次 commit
- message 形如：`day02: chapter1 1.0-1.2 + LC704/LC27 + 3 mini programs`
- 源码进仓库，构建产物（`.vs/` `x64/` 等）一律不进
