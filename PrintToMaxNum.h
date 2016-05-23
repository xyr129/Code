#pragma once

//功能：打印从1到最大的n位十进制数
//例如，输入3，按顺序打印1到999

//输入参数的合法性判断
//不考虑大数
void PrintToMaxNum(int n)
{
	if (n <= 0)
	{
		cout << "Input error!" << endl;
	}
	long long maxNum = 9;
	long long i = 1;
	while (i++ < n)
	{
		maxNum = maxNum * 10 + 9;
	}
	i = 1;
	while (i <= maxNum)
	{
		cout << i << " ";
		++i;
	}
	cout << endl;
}

//考虑大数
void PrintToMaxNum1();