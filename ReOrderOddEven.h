#pragma once

//功能：调整数组顺序，是偶数位于奇数前面

//初始状态：odd指向头，even指向尾
//odd从当前位置开始向后找到第一个奇数，even从当前位置开始向前找到第一个偶数，交换
//重复上述操作，直至走到odd>even

bool IsEven(int num)
{
	return num % 2 == 0;
}

void ReOrderOddEven(int* array, int size)
{
	assert(array);
	assert(size >= 0);

	int odd = 0;
	int even = size - 1;
	while (odd < even)
	{
		//找奇数
		while (odd < even && IsEven(array[odd]))
		{
			odd++;
		}
		//找偶数
		while (odd < even && !IsEven(array[even]))
		{
			even--;
		}
		if (odd < even)
		{
			swap(array[odd], array[even]);
		}
	}
}

