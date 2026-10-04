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
└── Project1_stdcout_sin_endl/              小练 01：输入输出
    ├── Project1_stdcout_sin_endl.slnx      解决方案（在 Visual Studio 里打开它）
    ├── Project1_stdcout_sin_endl.vcxproj   工程文件
    ├── Project1_stdcout_sin_endl.vcxproj.filters
    └── FileName.cpp                        源码：读入两个整数并回显
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

## 提交约定

- 每学完一节、每天至少一次 commit
- message 形如：`day02: chapter1 1.0-1.2 + LC704/LC27 + 3 mini programs`
- 源码进仓库，构建产物（`.vs/` `x64/` 等）一律不进
