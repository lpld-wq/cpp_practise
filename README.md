# cpp_practise

C++ 练习仓库 —— 记录从零开始学 C++ 的每一次课后小练。

- 教材：[C++学习网 studycpp.cn](https://www.studycpp.cn/)（[learncpp.com](https://www.learncpp.com/) 中文译站，28 章，每节带练习）
- 用法：**每节示例都必须手敲并改动一处**，只看不敲不算学完
- 长期目标：为 2027 年游戏客户端实习（C++ / UE5）打底；规划文档在 `D:\career_plan\docs\实习规划\`
- 最近更新：**2026-10-28**（13.1 / 13.3 枚举 ＋ 13.7 结构体传参两题；13.4~13.6 / 13.8 站内无题，只读）

---

## 当前进度

> 只写“现在在哪”；完整历史见 [练习记录](#练习记录)。

| 项 | 状态 |
| --- | --- |
| 教材进度 | **第 13 章 13.1~13.8 已读**（13.4~13.6 / 13.8 站内无题，只读；13.9 顺延 10/29） |
| 最近产出 | `13.1练习/`、`13.3练习/`、`13.7练习/`、`13.7练习2/` |
| 下一步 | **13.9~14.2**（10/29）＋ 项目推进；14.3 顺延 10/30 |
| 算法线 | Python 先行，链表专题进行中（10/22~10/29）；C++ 重做按 §7.4 排队（283 / 26） |
| 验收口径 | MSBuild `Rebuild`（Debug / x64）**exit=0、0 warning**；程序输出逐行比对 |
| 规划真源 | `D:\career_plan\docs\实习规划\游戏主线_十月逐日计划.md` |

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

## 快速导航

- [学习顺序索引](00_学习顺序.md)
- [当前进度](#当前进度)
- [环境](#环境)
- [怎么构建和运行](#怎么构建和运行)
- [练习记录](#练习记录)
- [目录结构](#目录结构)
- [编译 / 链接错误速查](#编译--链接错误速查)
- [源文件编码](#源文件编码)
- [知识点索引](#知识点索引)
- [提交约定](#提交约定)

---

## 怎么构建和运行

> 最短路径：打开对应 `.slnx` → **F5**；或在工程目录执行 `msbuild 工程.vcxproj /p:Configuration=Debug /p:Platform=x64`。

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

> 按日期**倒序**，最近的在最上面；日期列 = 提交日期，可与 `git log` 对上（只有小练 01 沿用练习日，实际提交在 10/04）。

| 日期 | 编号 | 文件 | 内容 | 知识点 |
| --- | --- | --- | --- | --- |
| 2026-10-28 | 小练 31 | `13.1练习/13.1_practise.cpp` | 站内 **13.1 非限定枚举**：`namespace MonsterType` 里定义同名 `enum`，实例化 `troll`，输出底层整数 `2`；MSBuild `Rebuild` **exit=0、0 warning** | 非限定枚举会隐式转 `int`；namespace 可避免枚举名与类型名冲突；输出的是枚举值不是枚举名 |
| 2026-10-28 | 小练 32 | `13.3练习/13.3_practise.cpp` | 站内 **13.3 限定枚举**：`enum class Animal` ＋ `getAnimalName` ＋ `printNumberOfLegs`；输出 `A cat has 4 legs.` / `A chicken has 2 legs.`；MSBuild `Rebuild` **exit=0、0 warning** | `enum class` 不隐式转 `int`，必须写 `Animal::cat`；`switch` 覆盖枚举值；`std::string_view` 返回字符串字面量 |
| 2026-10-28 | 小练 33 | `13.7练习/13.7_practise_1.cpp` | 站内 **13.7 结构体传参（Advertising）**：输入展示数 / 点击率 / 每次点击平均收益，按 `const Advertising&` 打印；输入 `100 / 2 / 1` → 总收益 `$2`；MSBuild `Rebuild` **exit=0、0 warning** | `struct` 可按值返回；`const&` 避免拷贝；总收益 = 展示数 × 点击率 / 100 × 每次点击平均收益，别把点击率写成平均收益 |
| 2026-10-28 | 小练 34 | `13.7练习2/13.7_practise_2.cpp` | 站内 **13.7 结构体传参（Fraction）**：两个分数相乘，输入 `2/3`、`4/5` → `8/15`；MSBuild `Rebuild` **exit=0、0 warning** | 聚合初始化 `Fraction{num, den}`；`const Fraction&` 传参；`constexpr` 函数可在运行期调用 |
| 2026-10-26 | 小练 29 | `12章练习/12_practise_extral.cpp` | 第 12 章 **E1~E4**：空指针检查 / `const int*` vs `int* const` / 指针传参与 `swap` / 返回引用与返回指针；**E5/E6 砍掉**；E4 的 `bad` 以注释保留 `C4172` 原文；验收输出 `7 / null / 6 / null / 6 10 / exchange / 10 6 / 20 / not found`（`at(arr,1)=20` 后数组为 `{1,20,3}`，再找 `2` 自然找不到），MSBuild `Rebuild` **exit=0、0 warning** | 空指针先判空再解引用；`const` 在 `*` 左边管对象、右边管指针；数组名退化为首元素指针；返回数组元素引用安全、返回局部变量引用悬垂；`find` 的 `return nullptr` 必须在循环外 |
| 2026-10-26 | 小练 30 | `12.14 十二章总结练习/12.14_practise.cpp` | 站内 **12.14 总结题**：`sort2(int& lesser, int& greater)` 用两个引用参数排序；验收 `7 5 / 5 7 / 5 7`，MSBuild `Rebuild` **exit=0、0 warning** | 引用传参直接改实参；`lesser > greater` 才交换；参数名表示调用后的顺序约束 |
| 2026-10-25 | 小练 27 | `11.8练习/11.8_practise.cpp` | 站内 **11.8 非类型模板参数**：`template <int N> constexpr int factorial()`，`main` 里 `static_assert(factorial<0>() == 1 / 3 == 6 / 5 == 120)`；故意写 `factorial<-3>()` 触发静态断言，原文留在注释里；MSBuild `Rebuild` **exit=0、0 warning** | 非类型模板参数是**编译期常量**；`constexpr` 函数可在编译期求值；`static_assert` 在**实例化时**检查；`N >= 0` 的断言写在函数体内，`factorial<-3>` 一实例化就失败 |
| 2026-10-25 | 小练 28 | `11.9问题二/11.9_practise.cpp` | 站内 **11.9 Q2**：`add<T>(T, T)`、`mult<T, U>(T, U)`、`sub<T, U>(T, U)` 三个函数模板；验收输出 `5 / 4.6 / 6 / 3.6 / 1 / 1.5 / 2.5`，MSBuild `Rebuild` **exit=0、0 warning** | 多模板类型参数 `<typename T, typename U>`；`auto` 返回类型由表达式推导（`int * double → double`）；同类型模板只接受两个同类型实参，混合类型要用双参数模板 |
| 2026-10-24 | 小练 26 | `第十章总结练习/10.9_practise.cpp` | 站内 **10.9 第 10 章总结**：`namespace constants` 里 `constexpr double pi`，两个 `using` 别名 `Degrees` / `Radians`，`convertToRadians` 把角度转弧度；验收输入 `180` → `180 degrees is 3.14159 radians.`，MSBuild `Rebuild` **exit=0、0 warning** | `using` 别名（比 `typedef` 可读）、`constexpr` 编译期常量、`namespace` 限定访问、`double` 乘除与 `std::cin` 读取 |
| 2026-10-22 | 小练 22 | `8.9练习/8.9_practise.cpp` | 站内 **8.9 `for`**：① 0~20 偶数；② `sumTo(n)` 累加 1~n；③ `fizzbuzz(n)` 同时处理 3 / 5 / 7 的倍数；验收输入 `10` → 偶数 11 行、`55`、`1 2 fizz 4 buzz fizz pop 8 fizz buzz`，MSBuild `Rebuild` **exit=0、0 warning** | `for` 三段式、`i += 2` 步长、`++i` 与 `i++` 在本处等价；三个**独立 `if` ＋ `printed` 标志**处理「同时是多个数的倍数」，避免 `else if` 漏掉 `15` 这类组合；中文源文件补 UTF-8 BOM（否则 MSVC 按 GBK 读源码 → 输出乱码） |
| 2026-10-22 | 小练 23 | `4.12练习2/4.12(8.15)_practise_2.cpp` | 站内 **8.15 总结 Q1（塔顶落球改写）**：把原来的 6 次手写调用改成 `while (calculateAndPrintBallHeight(...))`，落到地面（返回 0）自动停；验收 `10` → 0s 10m / 1s 5.1m / 2s 落地，`3.5` → 0s 3.5m / 1s 落地，MSBuild `Rebuild` **exit=0、0 warning** | **返回值当循环条件**（`double` → `bool`，0 为假）、`seconds` 由调用方维护、函数职责不变（算 / 打印 / 组合）；工程同步改了源文件名、`.vcxproj`、`.filters` 与 `ProjectName` |
| 2026-10-22 | 小练 24 | `8.15问题2/8.15_practise_q2.cpp` | 站内 **8.15 总结 Q2**：`isPrime(x)` 用 `for (test = 3; test * test <= x; test += 2)` 试除，`main` 里 17 条 `assert`（0/1/4/9/15/16/99 非素数，2/3/5/7/11/13/17/19/97/13417 素数）；验收输出 `Success!`，MSBuild `Rebuild` **exit=0、0 warning** | 先排除 `<= 1`、`2`、偶数，再只试奇数；`test * test <= x` 代替 `sqrt`（避免浮点）；`#undef NDEBUG` 放在 `<cassert>` 之前，保证断言在 Release 也生效 |
| 2026-10-22 | 小练 25 | `8.15_practise问题3/8.15_practise_q3.cpp` ＋ `random.h` | 站内 **8.15 总结 Q3（猜数字）**：`Random::get(1, 100)` 出题，7 次机会，提示 too high / too low，**第 7 次仍错 → `You lose`**，猜中 `break`，结束后问 `y/n` 重开；验收三条路径：首猜即中 → `Correct!You win!`、6 错 1 中 → 第 7 次获胜、7 次全错 → 只出现一次 `You lose`，输入 `n` → 正常退出，MSBuild `Rebuild` **exit=0、0 warning** | 复用 8.14 的 `random.h`（`inline std::mt19937` 全程序一份）、`while` 嵌套（外层重开 / 内层 7 次）、`break` 只跳出内层、`char` 读 `y/n`；「You lose」挂在 `token == 7` 的 too high / low 分支里，避免提前触发；⚠️ 首行 `std::cout << target //for test` 是调试输出，演示前可删 |
| 2026-10-21 | 小练 20 | `8.5练习/8.5_practise.cpp` | 站内 **8.5**：`calculate(x, y, sign)` 用 `switch` 分派 `+ - * / %`，`default` 打印 `calculate(): Unhandled case`；验收 6 组（`8 + 3`→11、`8 - 3`→5、`8 * 3`→24、`7 / 2`→3、`7 % 2`→1、`8 ? 3`→提示＋`is 0`），MSBuild `Rebuild` **exit=0、0 warning** | `switch` / `case` / `default`；分支用 `return` 提前退出，**不需要 `break`**；整数除法截断、取模符号跟被除数；题目明示**不考虑除数为 0**，故未做判断（真输入 0 → `0xC0000094`） |
| 2026-10-21 | 小练 21 | `8.7练习2~4/8.7_practise_2~4.cpp` ＋ `q3.cpp` ＋ `head.h` | 站内 **8.7 问题 2~4**（**单开新工程**）：Q2 `a~z` 打印字符＋码值；Q3 `5 4 3 2 1` 递减三角；Q4 带前导空格的 `1 / 2 1 / … / 5 4 3 2 1`；MSBuild `Rebuild` **exit=0、0 warning** | `while` ＋ `++` / `--` 计数器、`char` 自增按 ASCII 走、**嵌套循环**；⚠️ Q4 初版 `while (inner < 1)` **条件恒假、一行数字都不打印**，改 `inner > 0` 才恢复（编译器不报） |
| 2026-10-20 | 小练 18 | `7.13第七章总结练习/7.13_practise.cpp` ＋ `constants.h` | 站内 **7.13 问题 2**：新建 `constants.h`，在 `Constants` 命名空间里定义 `inline constexpr int maxClassSize{ 35 };`；主程序读取班级人数并比较；验收 `36` → too many、`35` / `20` → not too large，MSBuild `Rebuild` **exit=0、0 warning** | 命名空间 + 头文件共享常量、`inline constexpr` 变量、`#pragma once`、条件分支比较 |
| 2026-10-20 | 小练 19 | `7.13问题3/7.13_practise.cpp` | 站内 **7.13 问题 3**：`accumulate(int)` 用静态局部变量累加；验收 `4 / 3 / 2 / 1` → `4 / 7 / 9 / 10`，MSBuild `Rebuild` **exit=0、0 warning** | `static` 局部变量只初始化一次、跨调用保留状态；块作用域不变、静态存储期 |
| 2026-10-18 | 小练 16 | `六章总结练习/section_six_practise.cpp` | 站内 **6.7 第 6 章总结题**：`getQuantityPhrase`（negative / no / a single / a couple of / a few / many）＋ `getApplesPluralized`（1 → `apple`，其余 `apples`）；验收 `3` → `Mary has a few apples.` / `You have a few apples.`，`1` → `a single apple`，`0` → `no apples`，`4/10` → `many apples`，`-1` → `negative apples`；MSBuild `Rebuild` **exit=0、0 warning** | `std::string_view` 返回字符串字面量、`if` 链分派、条件运算符 `num == 1 ? "apple" : "apples"`；显式包含 `<string_view>`，不依赖其他头文件的间接包含 |
| 2026-10-18 | 小练 17 | `7.2练习/7.2_practise.cpp` | 站内 **7.2 局部变量**：读两个整数 `smaller` / `larger`，若 `smaller > larger` 用临时变量交换；验收 `5/3` → `3/5`、`3/5` → `3/5`、`4/4` → `4/4`、`-5/3` → `-5/3`，MSBuild `Rebuild` **exit=0、0 warning** | 局部变量 = 块作用域 ＋ 自动存储期；`int temp{ smaller };` 只在 `if` 块内存活；外层多包一层 `{}` 不影响结果（可用来演示块作用域） |
| 2026-10-17 | 小练 15 | `5.8习题/源.cpp` ＋ `5.11练习/5.11_practise.cpp` | 站内 **5.8 / 5.11 两道习题**（各自**单开新工程**）：5.8 姓名长度 + 年龄求和；5.11 输入两人姓名/年龄 → 打印更年长者；验收 `John Doe/32` → 40、`John Bacon/37 + David Jenkins/44` → `David Jenkins (age 44) is older than John Bacon (age 37).`，两个工程 MSBuild `Rebuild` **exit=0、0 warning** | `std::string` **可变**、`std::getline(std::cin >> std::ws, name)` 读整行、`std::ssize` 返回 `std::ptrdiff_t`（x64 = `__int64`）；`int len{ std::ssize(name) }` → **C2397**（列表初始化禁止隐式窄化，改用 `auto`）；`string_view` 只是指针 + 长度、不拥有内存 |
| 2026-10-16 | 小练 14 | `5.2~5.7练习/damage_calculator.cpp` ＋ `service.h` ＋ `service.cpp` | 站内 **5.2~5.7**：**自己设计**的伤害计算器（**单开新工程** `5.2~5.7练习\`）——基础攻击力 / 对手防御力 / 是否暴击 → 输出最终伤害；**暴击倍率链路**（`bool` → `kCritMultiplier` → `inline constexpr` 倍率）＋ **负伤害夹 0**；验收 6 组逐行一致：`100/50/0`→`50`、`100/50/1`→`150`、`20/50/1`→`0`、`20/50/0`→`0`、`0/50/1`→`0`、`7/2/1`→`12`，MSBuild `Rebuild` **exit=0、0 warning** | `inline constexpr` **变量**（`kCritMul` / `kNormalMul`：命名空间作用域的 `const` / `constexpr` **默认内部链接**，写 `inline` 才是全程序一份）；`constexpr` **函数**（标不标看**函数体纯不纯**，能不能编译期求值看**实参**）；5.5 **条件运算符** `crit ? kCritMul : kNormalMul`；关键点：`bool` 参与算术按 0/1 处理，暴击倍率要用 `kCritMultiplier` 显式映射；函数需要有调用点才会参与链接；`#include` 是预处理指令，行尾多写分号会触发 `C4067` |
| 2026-10-15 | 小练 13 | `5.0~5.1练习/5.0~5.1_practise.cpp` ＋ `service.h` ＋ `service.cpp` | 站内 **5.0~5.1 综合小练**：**圆面积**（**单开新工程** `5.0~5.1练习\`）；`const double kPi{ 3.14 };` 替掉魔法数字 ＋ `k` 前缀命名；验收：半径 `2` → `12.56`、`3` → `28.26` **逐行一致**，MSBuild `Rebuild` **exit=0、0 warning** | **命名常量**（给值起名，改一处全局改）；`const` ＝ **不可改**（声明处就得初始化，之后任何赋值 → `C3892`）；延伸：跨文件 `const` 的链接行为、`const double` 是否是常量表达式、运行期初始化的 `const`（→ `C2131`） |
| 2026-10-14 | 小练 12 | `4.12练习2/4.12_practise_2.cpp` | 站内 **4.12 章末练习二**：输入塔高 → 打印 **0~5 秒**每秒的球高（下落距离 `9.8 × t² ÷ 2`，落地后显示 `on the ground`）；**6 次调用手写**（循环 10/21 才解锁） | 验收（输入 **100**）：`100 / 95.1 / 80.4 / 55.9 / 21.6 / on the ground` **逐行一致**，MSBuild `Rebuild` **exit=0、0 warning**。函数按「**取数 / 计算 / 打印 / 两者合一**」四层拆；`ballHeight < 0.0` 时**返回 0** 而不是负数；`gravity * (seconds * seconds) / 2.0` 里 `seconds * seconds` 是 **int**，靠先乘 `gravity`（`double`）把整个表达式抬成浮点 —— **若写成 `(seconds * seconds / 2)` 会触发整数除法** |
| 2026-10-14 | 小练 11 | `4.7~4.12练习/4.7~4.12_practise_1.cpp` ＋ `service.h` ＋ `service.cpp` | 站内 **4.12 章末练习一**：把 2.12 的**整数**计算器改成**浮点**版（`int` → `double` 全链路）；源文件是**复制**进新工程的，**2.12 的 int 版原样保留** —— 两个工程互不影响 | 验收 4 组：`7/2`→**3.5**（2.12 的 int 版同输入是 `3`）、`5.5+2.25`→**7.75**、`7/0`→除零提示、`5%2`→非法运算符提示；MSBuild `Rebuild` **exit=0、0 warning**。**`7/2` 在 `double` 下是 3.5、在 `int` 下是 3**（整数除法）；**声明与定义要逐字一致**：参数类型不同会生成不同的重载符号，链接期报 `LNK2019`（见错误表第 2 条）；浮点 `y == 0` 属「判断输入是否恰好为 0」的例外场景 |
| 2026-10-13 | 小练 10 | `无符号整数及溢出测试/源.cpp` | 站内 **4.3~4.6** 实验（**单开新工程**）：`unsigned short` 溢出 —— `65536` 环绕成 `0`、`-1` 环绕成 `65535`；**有符号与无符号混用** —— `s < u` 里 `-1` 被转成 `4294967295` → 走 `else` | 取值范围（`n` 位无符号 = `0 ~ 2ⁿ−1`）与**环绕 wrap-around**；**无符号溢出是定义好的环绕、有符号溢出是 UB**；**混用时按无符号比较**（`C4018` 就是编译器在替你标出这件事）；本工程**保留** `C4305` / `C4309` / `C4018` 三条 warning（见错误表下方的例外说明） |
| 2026-10-12 | 小练 09 | `4.2sizeof表/4.2_sizeof_form.cpp` | 站内 **4.0~4.2**：打印本机 9 种基本类型的字节数（`bool / char / short / int / long / long long / float / double / long double`）＋ `int x{}; sizeof(x)`；MSBuild `Rebuild` **exit=0、0 warning**，输出 `1/1/2/4/4/8/4/8/8` 与 `x = 4`（**单开新工程**，没在 2.12 上续写） | **大小由类型决定、标准只规定「最小尺寸」（实际由实现决定 → 要跑出来看）**、`sizeof` 是**一元运算符**（`sizeof(类型)` / `sizeof(变量)` 都行）、**`void` 不是完整类型**（`sizeof(void)` → `C2070`）、`<iomanip>` 的 `std::left` / `std::setw` 属**库外壳**（可照抄） |
| 2026-10-11 | 小练 08 | `2.12简易计算器/simple_calculate.cpp` ＋ `service.h` ＋ `service.cpp` | 站内 **2.12 产出**：按**五步设计法自己设计**的简易计算器（`main` + 声明 + 定义三文件）；验收 6 组用例逐行核对通过：`8+3`→11、`8-3`→5、`8*3`→24、`7/2`→3、`5/0`→除零提示、`5%2`→非法运算符提示（MSBuild `Rebuild` exit=0、0 warning） | 五步设计法（目标→需求→工具与备份→**拆函数**→事件顺序）、`if / else if` 链分派＋`else` 兜底、整数除零判断、**声明与定义必须严格一致**（`int`/`char` 不一致 → `C2397`） |
| 2026-10-10 | 小练 07 | `2.9~2.11练习/2.9~2.11_practise.cpp` ＋ `add.h` ＋ `add.cpp` | 站内 2.9~2.11 自测：**头文件 + 实现**分离（**单开新工程**，没在 2.4~2.6 上续写）；编译运行输出 `add(10,20) = 30` | 头文件放声明 / `.cpp` 放定义、**include guard**、重复包含 vs 重复定义、`#include "…"` 与 `<…>` 的搜索路径差别 |
| 2026-10-10 | 小练 06 | `2.9示例测试/2.9test.cpp` | 站内 2.9 示例照敲：条件编译 `#define PRINT_JOE` + `#ifdef PRINT_BOB` → 只输出 `Joe` | 预处理器 ≠ 编译器、`#define`、`#ifdef` / `#endif`、条件编译 |
| 2026-10-08 | 小练 05 | `2.4~2.6练习/add_test.cpp` | 站内 2.7 多代码文件：把 `add_test.cpp` 加进**已有工程**，主文件调用**跨文件**的 `Add_Test`（A 卷输出 19 行逐行核对通过） | 多代码文件、声明与定义分离、跨文件调用、`LNK2019` / `LNK1120` 实验 |
| 2026-10-07 | 小练 04 | `2.4~2.6练习/2.4~2.6_practise.cpp` | 2.4~2.6 自测（T1~T4 + T7/T8）：局部变量生命周期 / 函数动机 / 前向声明；输出 18 行逐行核对通过 | 生命周期 vs 作用域、裸块、函数动机、**声明 vs 定义**、前向声明、链接期错误 |
| 2026-10-05 | 小练 03 | `2.0~2.3练习/2.1~2.3_practise.cpp` | 函数实验台：返回值 / `void` / 按值传递 / 函数复用（配 Obsidian 自测问答 Q1~Q8） | 函数头三件套、`return` 与「返回值被忽略」、形参也是局部变量、**按值传递** |
| 2026-10-05 | 自测 1.8 | `1.8自测/1.8practise.cpp` | 字面值与操作符：T1~T11 共 11 行输出自测（11/11 全对） | 字面值 vs 变量、一元/二元操作符、优先级、`<<` 的链接与返回值、副作用 |
| 2026-10-05 | 交付 01 | `10.4交付任务/main.cpp` | **BMI 计算**（第一版自己设计的程序：输入 → 计算 → 输出） | `double`、表达式求值、`cin` 连读 |
| 2026-10-04 | 小练 02 | `Project2_2倍输出输入值/1.10.cpp` | 站内 1.10 练习：输入一个整数 → 输出它的 2 倍 | `std::cin` 连续读取、算术表达式、`/` 与整数除法 |
| 2026-10-03 | 小练 01 | `Project1_stdcout_sin_endl/FileName.cpp` | `std::cout` 打印提示 → `std::cin` 读入两个 `int` → 回显 | `#include <iostream>`、`std::cout` / `std::cin`、`int x{ }` 值初始化 |

---

## 目录结构

> 按 studycpp 章节顺序浏览全部工程 → `00_学习顺序.md`；以下按新增时间与仓库目录展示。

### 最近新增（10/26~10/28）

| 目录 | 内容 | 验收 |
| --- | --- | --- |
| `13.1练习/` | 13.1 非限定枚举：`namespace MonsterType` ＋ 同名 `enum`，输出 `troll` 的底层整数 | exit=0、0 warning；`2` |
| `13.3练习/` | 13.3 限定枚举：`Animal` 名称与腿数 | exit=0、0 warning；`A cat has 4 legs.` / `A chicken has 2 legs.` |
| `13.7练习/` | 13.7 结构体传参：`Advertising` 输入 / 返回 / `const&` 打印 | exit=0、0 warning；`100 / 2 / 1` → 总收益 `$2` |
| `13.7练习2/` | 13.7 结构体传参：`Fraction` 两分数相乘 | exit=0、0 warning；`2/3 × 4/5` → `8/15` |
| `12章练习/` | 第 12 章 E1~E4：空指针 / `const` 指针 / 指针传参 / 返回引用与指针 | exit=0、0 warning；输出 `7 / null / 6 / null / 6 10 / exchange / 10 6 / 20 / not found` |
| `12.14 十二章总结练习/` | 12.14 总结题 `sort2`：两个 `int&` 参数排序 | exit=0、0 warning；`7 5 / 5 7 / 5 7` |
| `第十章总结练习/` | 10.9 章末总结：角度转弧度（`namespace constants` ＋ `constexpr pi` ＋ `using` 别名） | exit=0、0 warning；`180` → `3.14159` |
| `11.8练习/` | 11.8 非类型模板参数：`factorial<N>()` ＋ `static_assert` | exit=0、0 warning；`factorial<-3>` 的 E2784 原文留注释 |
| `11.9问题二/` | 11.9 Q2：`add<T>` / `mult<T,U>` / `sub<T,U>` 三个函数模板 | exit=0、0 warning；输出 `5 / 4.6 / 6 / 3.6 / 1 / 1.5 / 2.5` |

<details>
<summary>展开完整目录树</summary>

```
cpp_practise/
├── README.md
├── 00_学习顺序.md                          ← 按章节顺序排列的 35 个练习工程索引
├── .gitignore
├── Directory.Build.props                  ← 全仓库编译选项：让 MSVC 按 UTF-8 读源码（见「源文件编码」）
├── Project1_stdcout_sin_endl/             小练 01：输入输出
│   └── FileName.cpp                       源码：读入两个整数并回显（另有 .slnx / .vcxproj 等工程文件）
├── Project2_2倍输出输入值/                  站内 1.10 练习：输入整数 → 输出 2 倍
│   └── 1.10.cpp
├── 1.8自测/                                站内 1.8 自测：字面值与操作符
│   └── 1.8practise.cpp
├── 10.4交付任务/                           10/4 交付：BMI 计算（1.10 自己设计的程序）
│   └── main.cpp
├── 2.0~2.3练习/                            站内 2.0~2.3 自测：函数实验台（返回值 / void / 按值传递 / 复用）
│   └── 2.1~2.3_practise.cpp
├── 2.4~2.6练习/                            站内 2.4~2.6 自测：局部变量 / 函数动机 / 前向声明 + 报错实验（10/08 起含 2.7）
│   ├── 2.4~2.6_practise.cpp
│   └── add_test.cpp                        2.7 多代码文件：`Add_Test` 的定义（被主文件跨文件调用）
├── 2.9示例测试/                            站内 2.9 示例照敲：条件编译 `#define PRINT_JOE` / `#ifdef PRINT_BOB`
│   └── 2.9test.cpp
├── 2.9~2.11练习/                           **单开的新工程**（没在 2.4~2.6 上续写）：站内 2.9~2.11 自测
│   ├── 2.9~2.11_practise.cpp               只 `#include "add.h"` + 调用 `add`（实验报错原文留在注释里）
│   ├── add.h                               include guard + **只放声明**（`int add(int x, int y);`）
│   └── add.cpp                             放定义（已 `#include "add.h"`，编译器可核对声明与定义一致）
├── 2.12简易计算器/                         站内 2.12 产出（10/11）：**自己设计 + 自己拆函数**的三文件版简易计算器
│   ├── simple_calculate.cpp                `main` 装配四步：**先算再打印**（`int result{ getResult(...) };`）
│   ├── service.h                           `#pragma once` + **只放声明**（第一条就是 `char getSymbol();`）
│   └── service.cpp                         `#include "service.h"` + **四个函数定义**（`if / else if` 链分派）
├── 4.2sizeof表/                             站内 4.0~4.2 产出（10/12）：`sizeof` 与「大小由实现决定」
│   └── 4.2_sizeof_form.cpp                 打印 9 种基本类型字节数 + `sizeof(x)`；`sizeof(void)` 的报错原文留在注释里
├── 无符号整数及溢出测试/                      站内 4.3~4.6 实验（10/13）：有符号 / 无符号与「环绕」
│   ├── 无符号整数及溢出测试(4.3~4.6).slnx
│   └── 源.cpp                               `unsigned short` 溢出（`65536` 环绕成 `0`、`-1` 环绕成 `65535`）+ 有符号与无符号混用（`s < u` 走 `else`）
├── 4.7~4.12练习/                             站内 **4.12 章末练习一**（10/14）：把 2.12 的**整数**计算器改成**浮点**版
│   ├── 4.7~4.12练习.slnx / .vcxproj         **单开新工程**（源文件都在本文件夹里，不再跨工程引用）
│   ├── service.h / service.cpp              `double getFirstNumber / getSecondNumber / getResult` —— **声明与定义逐字一致**
│   └── 4.7~4.12_practise_1.cpp              `main`：三次输入 → `double result{ getResult(x, op, y) };` → 打印
├── 4.12练习2/                                站内 **4.12 章末练习二 + 8.15 Q1**（10/14 建，10/22 改）：塔顶落球
│   ├── 4.12练习2.slnx / .vcxproj             **单开新工程**（10/22 源文件改名，`ProjectName` 改为「4.12练习2(8.15总结修改任务)」）
│   └── 4.12(8.15)_practise_2.cpp             `getTowerHeight` / `calculateBallHeight` / `printBallHeight` / `calculateAndPrintBallHeight` ＋ `main` 用 **`while` 循环**（0 秒起，落地即停）
├── 5.0~5.1练习/                              站内 **5.0~5.1**（10/15）：圆面积 —— 命名常量 ＋ `const`
│   ├── 5.0~5.1练习.slnx / .vcxproj            **单开新工程**（Debug / x64，没在 4.12 上续写）
│   ├── service.h                              `#pragma once` + 两条函数声明 + **`const double kPi{ 3.14 };`**
│   ├── service.cpp                            `kGetRadius()`（`std::cin` 读半径）/ `kGetResult(radius)`（`radius * radius * kPi`）；⚠️ **原名 `servise.cpp`，10/15 改名并已同步 `.vcxproj` / `.filters`**
│   └── 5.0~5.1_practise.cpp                   `main`：取半径 → 算面积 → 打印
├── 5.2~5.7练习/                              站内 **5.2~5.7**（10/16）：伤害计算器 —— `constexpr` ＋ `inline` 变量 ＋ 条件运算符
│   ├── 5.2~5.7练习.slnx / .vcxproj            **单开新工程**（Debug / x64）
│   ├── service.h                              `#pragma once` ＋ `inline constexpr double kCritMul{ 2.0 }` / `kNormalMul{ 1.0 }` ＋ `constexpr kCritMultiplier(bool)`（5.5 条件运算符）＋ `constexpr kDamegeCulculate(akt, defence, mult)`
│   ├── service.cpp                            三个取数函数 `kGetAktDate` / `kGetDefendDate` / `kGetCritDate` —— 每个只 `std::cin` 一个值、`return` 一个值
│   └── damage_calculator.cpp                  `main`：三次取数 → `kDamegeCulculate(akt, defence, kCritMultiplier(crit))` → **负伤害夹 0** → 打印
├── 5.8习题/                                  站内 **5.8 习题**（10/17）：姓名长度 + 年龄求和
│   ├── 5.8习题.slnx / .vcxproj               **单开新工程**（Debug / x64）
│   └── 源.cpp                                `std::getline` 读整行 + `std::ssize(name)` 取有符号长度 + `age + len_name`
├── 5.11练习/                                站内 **5.11 习题**（10/17）：两个人比年龄
│   ├── 5.11练习.slnx / .vcxproj              **单开新工程**（Debug / x64）
│   └── 5.11_practise.cpp                    `kGetName` / `kGetAge` / `kCompare` + `main` 两轮输入 → 打印更年长者
├── 六章总结练习/                             站内 **6.7 第 6 章总结题**（10/18）：数量短语 ＋ 苹果复数
│   ├── 六章总结练习.slnx / .vcxproj          **单开新工程**（Debug / x64）
│   └── section_six_practise.cpp            `getQuantityPhrase` / `getApplesPluralized`
├── 7.2练习/                                  站内 **7.2 局部变量**（10/18）：两整数排序 / 交换
│   ├── 7.2练习.slnx / .vcxproj               **单开新工程**（Debug / x64）
│   └── 7.2_practise.cpp                      `smaller` / `larger` ＋ 临时变量交换
├── 7.13第七章总结练习/                        站内 **7.13 Q2**（10/20）：`constants.h` ＋ 班级人数比较
│   ├── 7.13第七章总结练习.slnx / .vcxproj    **单开新工程**（Debug / x64）
│   ├── 7.13_practise.cpp                     `main`：读取人数并与 `Constants::maxClassSize` 比较
│   └── constants.h                           `#pragma once` ＋ `inline constexpr int maxClassSize{ 35 };`
├── 7.13问题3/                                站内 **7.13 Q3**（10/20）：静态局部变量累加器
│   ├── 7.13问题3.slnx / .vcxproj             **单开新工程**（Debug / x64）
│   └── 7.13_practise.cpp                     `accumulate(int)` 用 `static int` 保存累计和
├── 8.5练习/                                  站内 **8.5**（10/21）：`switch` 版四则计算器
│   ├── 8.5练习.slnx / .vcxproj               **单开新工程**（Debug / x64）
│   └── 8.5_practise.cpp                      `calculate(x, y, sign)`：`switch` 分派 `+ - * / %`，`default` 兜底
├── 8.7练习2~4/                                站内 **8.7 Q2~Q4**（10/21）：字母表 ＋ 两个三角形
│   ├── 8.7练习2~4.slnx / .vcxproj            **单开新工程**（Debug / x64）
│   ├── head.h                                `#pragma once` ＋ 两条函数声明
│   ├── 8.7_practise_2~4.cpp                  `main`：`a~z` 字符＋码值，再调用两个三角形函数
│   └── q3.cpp                                `kCout_Five_To_One`（5→1 递减）/ `k_Reverse_One_To_Five`（带前导空格的 1 / 2 1 / … / 5 4 3 2 1）
├── 8.9练习/                                  站内 **8.9 `for`**（10/22）：偶数表 ＋ 累加 ＋ fizzbuzz
│   ├── 8.9练习.slnx / .vcxproj               **单开新工程**（Debug / x64）
│   └── 8.9_practise.cpp                      `sumTo(n)` / `fizzbuzz(n)` ＋ `main` 里 0~20 偶数
├── 8.15问题2/                                站内 **8.15 Q2**（10/22）：`isPrime` ＋ `assert`
│   ├── 8.15问题2.slnx / .vcxproj             **单开新工程**（Debug / x64）
│   └── 8.15_practise_q2.cpp                  `#undef NDEBUG` ＋ 17 条 `assert`，输出 `Success!`
├── 8.15_practise问题3/                       站内 **8.15 Q3**（10/22）：猜数字（7 次机会 ＋ 重开）
│   ├── 8.15_practise问题3.slnx / .vcxproj    **单开新工程**（Debug / x64，含 `random.h`）
│   ├── random.h                              8.14 的 `Random` 命名空间（`inline` 全局 `mt19937` ＋ `get`）
│   └── 8.15_practise_q3.cpp                   `while` 外层重开 / 内层 7 次 ＋ too high / too low 提示
├── 第十章总结练习/                           站内 **10.9 章末总结**（10/24）：角度转弧度
│   ├── 第十章总结练习.slnx / .vcxproj        **单开新工程**（Debug / x64）
│   └── 10.9_practise.cpp                     `namespace constants` ＋ `constexpr pi` ＋ `using Degrees/Radians`
├── 11.8练习/                                  站内 **11.8 非类型模板参数**（10/25）：`factorial<N>()`
│   ├── 11.8练习.slnx / .vcxproj               **单开新工程**（Debug / x64）
│   └── 11.8_practise.cpp                      `static_assert` 0/3/5；`factorial<-3>` 的 E2784 原文留注释
├── 11.9问题二/                                站内 **11.9 Q2**（10/25）：多类型函数模板
│   ├── 11.9问题二.slnx / .vcxproj             **单开新工程**（Debug / x64）
│   └── 11.9_practise.cpp                      `add<T>` / `mult<T,U>` / `sub<T,U>`
├── 12章练习/                                 第 12 章 E1~E4（10/26）：空指针 / const 指针 / 指针传参 / 返回引用与指针
│   ├── 12章练习.slnx / .vcxproj              **单开新工程**（Debug / x64）
│   └── 12_practise_extral.cpp                E1 `printValue` / E3 `addOne`+`swap` / E4 `at`+`find`；`bad` 以注释保留 C4172
├── 12.14 十二章总结练习/                      站内 12.14 总结题（10/26）：`sort2` 两引用参数排序
│   ├── 12.14 十二章总结练习.slnx / .vcxproj   **单开新工程**（Debug / x64）
│   └── 12.14_practise.cpp                    `sort2(int&, int&)` + `std::swap`
├── 13.1练习/                                 站内 13.1 非限定枚举（10/28）：`namespace MonsterType` ＋ 同名 `enum`
│   ├── 13.1练习.slnx / .vcxproj              **单开新工程**（Debug / x64）
│   └── 13.1_practise.cpp                     实例化 `troll`，输出底层整数 `2`
├── 13.3练习/                                 站内 13.3 限定枚举（10/28）：`Animal` 名称与腿数
│   ├── 13.3练习.slnx / .vcxproj              **单开新工程**（Debug / x64）
│   └── 13.3_practise.cpp                     `getAnimalName` ＋ `printNumberOfLegs`
├── 13.7练习/                                 站内 13.7 结构体传参（10/28）：`Advertising`
│   ├── 13.7练习.slnx / .vcxproj              **单开新工程**（Debug / x64）
│   └── 13.7_practise_1.cpp                   `getAdvertising` 返回结构体；`const&` 打印；总收益公式
└── 13.7练习2/                                站内 13.7 结构体传参（10/28）：`Fraction`
    ├── 13.7练习2.slnx / .vcxproj             **单开新工程**（Debug / x64）
    └── 13.7_practise_2.cpp                   `multiply` 两分数相乘；`2/3 × 4/5` → `8/15`
```

</details>

> `.vs/`、`x64/`，以及 VS 2026 为**每个工程**生成的同名中间目录（`Project1.e7d0550b/`、`2.4~2.6练习/2.4~2.6练习/` 这类）都是本机构建产物，已被 `.gitignore` 排除，不会进仓库。
> 如果以后 VS 又生成了新的中间目录，把它加进 `.gitignore` 即可。

---

## 编译 / 链接错误速查

**先看这 5 条（最高频）**

- `C2065`：变量不在作用域 → 检查 `{}` 的范围。
- `C3861`：函数没声明 → 补前向声明 / 检查拼写。
- `LNK2019` + `LNK1120`：声明了但没定义 → 补定义 / 检查签名是否一致。
- `LNK1169`：多重定义 → 头文件里别放定义。
- `C2397`：列表初始化窄化 → 换 `auto` 或显式 `static_cast`。

> 全部是**故意写错**换来的原文，**不是从教材抄的**。教材（studycpp 2.6）贴的是 `LNK2001`，本机 MSVC 14.51 给的是 **`LNK2019`** —— 编译器版本不同编号会变，**一律以自己屏幕上的原文为准**。
> ⚠️ 下面的行号属于**当时那一版**代码，改动之后就对不上了。

| 编号 | 怎么触发的 | 本机实抄原文 | 卡在哪个阶段 |
|---|---|---|---|
| `C2065` | 在 `inner` 所在的花括号**之外**使用它 | `error C2065: “inner”: 未声明的标识符` | **编译期**（作用域规则） |
| `C3861` | 调用一个**尚未声明**的函数（定义放在 `main` 之后、又没写前向声明） | `error C3861: “add”: 找不到标识符` | **编译期**（前向声明的作用） |
| `LNK2019` + `LNK1120` | **只前向声明、从未定义，却调用了它** | `error LNK2019: 无法解析的外部符号 "int __cdecl test(int)" (?test@@YAHH@Z)，函数 main 中引用了该符号`<br>`fatal error LNK1120: 1 个无法解析的外部命令` | **链接期**（声明 ≠ 定义） |
| `LNK2019` + `LNK1120`（**同编号第 2 次**） | **声明改了、定义没改**：`service.h` 声明 `double getResult(double, char, double)`，`service.cpp` 的定义还是 `int getResult(int, char, int)`（10/14 做 4.12 练习一、把计算器改成浮点版时实验中记录的） | `error LNK2019: 无法解析的外部符号 "double __cdecl getResult(double,char,double)" (?getResult@@YANNDN@Z)，函数 main 中引用了该符号`<br>`已定义且可能匹配的符号上的提示: "int __cdecl getResult(int,char,int)" (?getResult@@YAHHDH@Z)`<br>`fatal error LNK1120: 1 个无法解析的外部命令` | **链接期**（⚠️ **这次编译器一句都没说** —— 参数类型也不一样，那是**另一个重载**，两边各自都合法，只有链接器能发现） |
| `LNK1169`（多重定义） | 把 `add` 的**定义**放进 `add.h`，两个 `.cpp` 又都 include 它 → 每个 `.obj` 各带一份定义，链接器撞车（10/10 做 2.11 对照实验时实验中记录的；原文记在 `2.9~2.11练习/add.cpp` 第 3~4 行注释） | `fatal error LNK1169: 找到一个或多个多重定义的符号` | **链接期**（**头文件里不该放定义**） |
| `C2397` | **声明与定义返回类型不一致**：`service.h` 里声明 `int getSymbol();`、`service.cpp` 里定义 `char getSymbol()` → 调用处 `char op{ getSymbol() };` 就等于把 `int` 塞进 `char`（10/11 做 2.12 时实验中记录的） | `error C2397: 从 "int" 转换到 "char" 需要收缩转换` | **编译期**（**列表初始化禁止窄化** —— 这条检查在这里救了命，见下面的连锁说明） |
| `C2397`（**同编号第 2 次**） | `int len_name{ std::ssize(name) };` —— `std::ssize` 返回 `std::ptrdiff_t`（x64 = `__int64`），`{}` 列表初始化**禁止隐式窄化**（10/17 做 5.8 习题时实验中记录的） | `error C2397: 从“__int64”转换到“int”需要收缩转换` | **编译期**（`std::ssize` 本身已经是**有符号** 64 位；要接 `int` 得显式 `static_cast<int>`，或直接用 `auto` 保持 `ptrdiff_t`） |
| `C2568` ⚠️ | 同一次实验里的另一条（报在 `std::cout << add(10, 20)` 那行）—— **触发状态待复核**：当时 `add.h` 里到底放了什么没留下完整现场，原文记在 `2.9~2.11_practise.cpp` 第 3 行注释 | `error C2568: '<<': 无法解析函数重载` | 编译期（⚠️ 与站点 2.11 预期的 `C2084` 不一致，**要重做一次确认**） |
| `C2070` | `std::cout << sizeof(void)` —— `void` **不是完整类型**，`sizeof` 对它无意义（10/12 做 4.2 实验时实验中记录的；原文留在 `4.2sizeof表/4.2_sizeof_form.cpp` 第 16 行注释里） | `error C2070: 'void': 格式错误的 sizeof 操作数` | **编译期**（`void` 只表示「无返回值 / 无参数」，不存在 `void` 变量） |
| `C2129` | `static int add(int, int);` **只声明不定义**，**而且在 `main` 里调用了它**（10/12 的「声明 vs 定义」实验） | `error C2129: 静态函数“int add(int,int)”已声明但未定义`<br>`note: 参见“add”的声明` | **编译期**（⚠️ 触发条件是**被调用**；只声明不调用时 MSVC **一条诊断都不给**） |
| `C4305` | `x = 65536;`（`x` 是 `unsigned short`）—— **赋值时的截断**（10/13 做 4.3~4.6 实验时编译器给的；`x = 65537;` 同样报） | `warning C4305: “=”: 从“int”到“unsigned short”截断` | **编译期警告**（不是错误 —— 程序照跑，输出的 `0` 就是这条警告说的"截断/环绕"现场） |
| `C4309` | 同上那一行的**常量值**截断（与 `C4305` 成对报出，两行指同一个位置） | `warning C4309: “=”: 截断常量值` | **编译期警告** |
| `C4018` | `if (s < u)`：`s` 是 `int`、`u` 是 `unsigned int` → **有符号/无符号不匹配**（正是 4.4 要讲的那个陷阱） | `warning C4018: “<”: 有符号/无符号不匹配` | **编译期警告**（**它就是在替你标出「这里发生了隐式转换」**） |
| `C3892` | 给 `const` 常量赋值 —— 做 5.0 小练时写 `kPi = 3.15;`（原文也抄在 `5.0~5.1练习/service.h` 第 3 行行尾） | `error C3892: “kPi”: 赋值给类型为 'const double' 的常量限定 变量` | **编译期**（`const` 是**只读**：必须在声明处初始化，之后任何赋值都是错误） |
| `C4715` | `find` 循环结束后没有兜底 `return`（`return nullptr;` 误放在循环里或缺失） | `warning C4715: “find”: 不是所有的控件路径都返回值` | **编译期警告**（非 `void` 函数所有路径都要返回值；`for` 可能一次都不执行，循环外的 `return` 不能省） |
| `C4172` | `int& bad()` 返回局部变量 `local` | `warning C4172: 返回局部变量或临时变量的地址: local` | **编译期警告**（局部变量生命周期随函数结束；返回引用/指针会悬垂） |
| `C4067` | `<iostream>` 那行写成 `#include <iostream>;` —— **`#include` 后面多写了一个分号**（10/16 做 5.2~5.7 伤害计算器时实验中记录的） | `warning C4067: 预处理器指令后有意外标记 - 应输入换行符` | **编译期警告**（预处理指令到行尾就结束，后面的 `;` 是多余标记；C++11 起单独一个 `;` 是合法空声明，所以只是警告不是错误） |

> ⚠️ **「exit=0、零 warning」验收口径的例外（2026-10-13 立）**：`无符号整数及溢出测试` 这类**溢出/混用实验天生带 warning** —— `C4305` / `C4309` / `C4018` 就是**实验现象本身**。所以这条线上只要求 **exit=0**，**不许为了让 warning 消失去改掉 `x = 65536;` 或把 `s < u` 改成强转**（那等于把实验改没）。要留证据就把原文抄进本表。

> 🧪 **2026-10-12「声明 vs 定义」实验（本机 MSVC 19.51.36260 实测，四种形状）**：
> ① `int add(int,int);` **只声明、不定义、不调用** → 编译链接**全过、零诊断**（`/W3` 与 `/W4` 都一样）；
> ② 在 `main` 里加 `add(1,2);` → **`LNK2019` + `LNK1120`**（链接期，见上表）；
> ③ `static int add(int,int);` **只声明、不定义、也不调用** → **同样零诊断**（换成 C 语言模式编译也一样）；
> ④ **只有调用**那个 static 函数时，才报 **`C2129`**（编译期错误）。
> ⇒ **口径修正**：`C2129` 的触发条件是「**static 函数被调用过、却没有定义**」，**不是**「static 只声明不定义」—— 只声明不调用时，**普通函数和 static 函数都一条诊断都不给**。

**这几条连起来说明的事**：编译器**从上往下**读代码 —— 读到调用时若还不知道这个函数存在，**当场报错**（C3861）；补一行声明就够它「知道长什么样」，于是**编译通过**；但声明只是承诺存在，**真正的函数体**要等**链接器**去找，找不到就是 LNK2019 / LNK1120。**同一个函数的声明可以出现多次，定义只能有一次。**

> 🎯 **2026-10-11（`C2397` 的连锁 —— 做 2.12 时踩到的）**：把 `char op{ getSymbol() };` 改成 **`char op = getSymbol();`（用 `=`）只会给 `C4244` 警告、能编过** —— 但 MSVC 的修饰名**带返回类型**：声明那份引用的是 `int` 版符号、定义只有 `char` 版 → **链接期 `LNK2019: 无法解析的外部符号 "int __cdecl getSymbol(void)"`**。
> 两条结论：① **列表初始化 `{}` 的窄化检查是朋友**，它把「声明/定义不一致」顶到了编译期；② **定义文件必须 `#include` 自己的头文件**（`service.cpp` 第 2 行就是这么做的），这样编译器会在编译期替你把「声明 vs 定义」逐条比一遍。
> 📌 **`E####` ≠ `C####`**：VS「错误列表」里的 `E0065`（应输入 `";"`）/ `E0020`（未定义标识符）是 **IntelliSense** 的即时提示；对应的**编译器原文**是 `C2143`（缺少 `;`）/ `C2065`（未声明的标识符）。抄进本表的一律是**「输出」窗口里的 `C####` / `LNK####`**。

> 🧪 **2026-10-25（11.8 非类型模板参数）**：故意写 `factorial<-3>()`，VS「错误列表」先给 **`E2784`（IntelliSense 静态断言）**，原文抄在 `11.8练习/11.8_practise.cpp` 的注释里。按上一条「`E####` ≠ `C####`」的规矩，**暂不入本表**；等拿到「输出」窗口的 `C####` 原文再补行。

> 🔍 **2.10 / 2.11 顺带核实的一条（2026-10-10）**：头文件里**只有声明**时，重复包含**其实不报错**（同一个函数声明多次是合法的）—— include guard 不是为「声明」兜底，而是为**将来头里会出现的定义 / 类型 / 常量**兜底。反过来，一旦头里放了**定义**，两个 `.cpp` 各编译一次就得到两份定义 → 链接期 `LNK1169`。所以规矩是：**头文件只放声明，定义放 `.cpp`**。

---

## 源文件编码

> 踩过坑，别再踩。

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
  - **2026-10-11 实测（反向印证这条设计）**：`2.12简易计算器` 三个文件**都是无 BOM 的 UTF-8**，MSVC 14.51 靠 `Directory.Build.props` 的 `/source-charset:utf-8` **零警告**编过；中文提示语的**输出字节是 GBK**（`C7 EB CA E4 …` = 「请输入」），在 936 控制台下显示正常 —— 正是「只设 source-charset、窄字符串按 GBK 落地」想要的效果。**但防线②（存 BOM）仍建议照办**：换 clang / Linux / GitHub CI 时没有 `Directory.Build.props` 兜底。
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
- **2026-10-18 实测**：`六章总结练习` 与 `7.2练习` 的源文件都是无 BOM 的 UTF-8，靠 `Directory.Build.props` 零警告编过（其中 `六章总结练习` 含中文注释）。

---

## 知识点索引

> 按 studycpp 章节整理，用于面试前快速回忆；每条都能在对应工程里找到可运行代码。

| 章节 | 知识点 | 对应产出 |
| --- | --- | --- |
| 第 1 章 | 程序结构、`main`、`#include`、`std::cout` / `std::cin`、变量声明与值初始化、字面值、运算符优先级与结合性、副作用 | `Project1_stdcout_sin_endl/`、`1.8自测/`、`Project2_2倍输出输入值/` |
| 第 2 章 | 函数声明与定义、返回值、参数、按值传递、局部变量与生命周期、多代码文件、头文件与 include guard、预处理与条件编译、命名空间 | `2.0~2.3练习/`、`2.4~2.6练习/`、`2.9示例测试/`、`2.9~2.11练习/`、`2.12简易计算器/` |
| 第 3 章 | 调试：断点、监视、调用堆栈、逐语句 / 逐过程 | 学习记录（Obsidian `cpp知识库\调试`） |
| 第 4 章 | 基本类型与 `sizeof`、有无符号、溢出与环绕、浮点精度、`static_cast`、`if / else` 分支、布尔逻辑 | `4.2sizeof表/`、`无符号整数及溢出测试/`、`4.7~4.12练习/`、`4.12练习2/` |
| 第 5 章 | `const` / `constexpr`、字面值与进制、条件运算符、`inline` 变量、`std::string`、`std::string_view`、`std::getline`、`std::ssize` | `5.0~5.1练习/`、`5.2~5.7练习/`、`5.8习题/`、`5.11练习/` |
| 第 6 章 | 运算符优先级与结合性、算术 / 取模 / `std::pow`、自增自减与副作用、逗号运算符、关系运算与浮点比较、逻辑运算与短路 | `六章总结练习/` |
| 第 7 章（7.0~7.13） | 代码块与块作用域、命名空间与 `::`、局部变量、全局变量、名称遮挡、内部/外部链接、`static` 局部变量、`inline constexpr` | `7.2练习/`、`7.13第七章总结练习/`、`7.13问题3/` |
| 第 8 章（8.0~8.15） | 控制流、`if / else if / else` 链、`switch`（`case` / `default` / 穿透）、`goto`、`while` / `do-while` / `for`、`break` / `continue`、嵌套循环、随机数（`mt19937` / 种子 / 分布）、`assert` | `8.5练习/`、`8.7练习2~4/`、`8.9练习/`、`4.12练习2/`、`8.15问题2/`、`8.15_practise问题3/` |
| 第 9 章（9.0~9.6） | 代码测试、代码覆盖率、常见语义错误、检测与处理错误、`std::cin` 无效输入、`assert` | `8.15问题2/`（`assert`）；其余见 Obsidian `cpp知识库` |
| 第 10 章（10.0~10.9） | 隐式转换、数值提升 / 数值转换、窄化与列表初始化、算术转换、`static_cast`、`typedef` / `using`、`auto`、函数返回类型推导 | `第十章总结练习/` |
| 第 11 章（11.0~11.9） | 函数重载、重载决议、`= delete`、默认参数、函数模板、模板实例化、多模板类型、非类型模板参数 | `11.8练习/`、`11.9问题二/` |
| 第 12 章（12.0~12.14） | 值类别、左值引用、`const` 引用、引用传参、指针、空指针、指针与 `const`、指针传参、返回引用/指针、in/out 参数、`auto` 推导 | `12章练习/`、`12.14 十二章总结练习/` |
| 第 13 章（13.1~13.8） | 非限定 / 限定枚举、枚举输入输出、`struct` 定义与初始化、成员默认初始化、结构体按值 / 引用 / 指针传参 | `13.1练习/`、`13.3练习/`、`13.7练习/`、`13.7练习2/` |
| 工程实践 | 多工程组织、`.vcxproj` / `.filters` 同步、MSBuild `Rebuild`、`Directory.Build.props` 统一编译选项、UTF-8 源码字符集 | 全仓库 |

---

## 提交约定

- 每学完一节、每天至少一次 commit
- message 形如：`day02: chapter1 1.0-1.2 + LC704/LC27 + 3 mini programs`
- 源码进仓库，构建产物（`.vs/` `x64/` 等）一律不进
- README 的「练习记录」表**在每次提交之后**补上当天那一行（2026-10-10 起由 DSH 代笔）
- 报错原文一律写**自己屏幕上抄下来的**；教材版本（studycpp 2.6 写的是 `LNK2001`）可能与本机编号不同，**以实测为准**
- 提交前先更新「当前进度」与「练习记录」；`git add` 具体文件，不要 `git add -A`（根目录 `AGENTS.md` 不提交）。
