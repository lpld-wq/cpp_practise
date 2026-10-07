#include <iostream>

void makeThree()
{
	int a{ 1 };
	std::cout << a << "\n" ;

	int b{ 2 };
	std::cout << b << "\n";

	int c{ 3 };
	std::cout << c << "\n";
}

int addOne(int x)
{
	return x + 1;
}

void showSum(int p, int q)
{
	std::cout << p << "\n";
	std::cout << q << "\n";
	std::cout << p + q << "\n";

}

int add(int , int );
int test(int);

int main()
{
	makeThree();
	makeThree();

	int outer{ 10 };
	std::cout << "T1 outer = " << outer << "\n";
	{
		int inner{ 20 };
		std::cout << "T2 inner = " << inner << "\n";
	}
	std::cout << "T3 outer = " << outer << "\n";  //1>D:\cpp_practise\2.4~2.6练习\2.4~2.6_practise.cpp(24,23): error C2065: “inner”: 未声明的标识
	
	int x{ 100 };
	std::cout <<  x << "\n";
	std::cout << "T4 addOne(x) = " << addOne(x) << "\n";

	showSum(3, 4);
	showSum(10, 20);
	
	int y{ 2 };

	std::cout << add(x, y)<< "\n";//无前向声明时报错  >D:\cpp_practise\2.4~2.6练习\2.4~2.6_practise.cpp(49,2): error C3861: “add”: 找不到标识符
								  //把声明改成 int add(int, int)依旧可编译
								  //只有声明、没有定义
								  //1>2.4~2.6_practise.obj : error LNK2019: 无法解析的外部符号 "int __cdecl test(int)" (?test@@YAHH@Z)，函数 main 中引用了该符号
								  //D:\cpp_practise\2.4~2.6练习\x64\Debug\2.4~2.6练习.exe : fatal error LNK1120 : 1 个无法解析的外部命令
}

int add(int x, int y)
{
	return x * y ;
}