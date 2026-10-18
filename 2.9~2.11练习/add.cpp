#include "add.h"

// 实验记录：把头文件里的声明改成定义后，两个 .cpp 各带一份定义
// → fatal error LNK1169: 找到一个或多个多重定义的符号

int add(int x, int y)
{
	return x + y;
}