#pragma once

//功能：统计二进制中1的个数

//用1和输入数字做与运算，左移1
//不要右移输入数字，万一它是个负数呢

int CountBitWithOne(int num)
{
	int count = 0;
	size_t flag = 1;
	while (flag)
	{
		if (flag & num)
		{
			++count;
		}
		flag = flag << 1;
	}
	return count;
}

int CountBitWithOne1(int num)
{
	int count = 0;
	while (num)
	{
		++count;
		num = num&(num - 1);
	}
	return count;
}

void TestCountBitWithOne()
{
	cout << CountBitWithOne(255) << endl;
	cout << CountBitWithOne1(255) << endl;
}