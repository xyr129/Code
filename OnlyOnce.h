#pragma once

//功能：一组数中仅有两个只出现一次的数字，其余数字成对出现

//采用异或将所有数字异或，得到的结果是两个只出现一次数字的异或
//找到这个异或结果二进制第一个1的位（即两个数第一个不同的位）
//把数组中的数按该位是1或者0分成两组

int XOR_All(int *array, int size)
{
	assert(array);
	assert(size > 0);
	int xor = 0;
	for (int i = 0; i < size; ++i)
	{
		xor ^= array[i];
	}
	return xor;
}

int GetOneIndex(int num)
{
	if (0 == num)
	{
		return -1;
	}

	int index = 0;
	while (num)
	{
		if (1 == (num&(1 << index)))
		{
			return index;
		}
		++index;
	}
}

bool OnlyOnce(int *array, int size, int& num1, int& num2)
{
	assert(array);
	assert(size > 0);
	int xor = XOR_All(array, size);
	int index = GetOneIndex(xor);
	if (-1 == index)
	{
		return false;
	}

	for (int i = 0; i < size; ++i)
	{
		if (1 == (array[i] & (1 << index)))
		{
			num1 ^= array[i];
		}
		else
		{
			num2 ^= array[i];
		}
	}
	return true;
}

void TestOnlyOnce()
{
	int array[10] = { 9, 2, 3, 4, 5, 2, 3, 4, 5, 6 };
	int num1 = 0;
	int num2 = 0;
	cout << "是否存在只出现一次的数字: " << OnlyOnce(array, 10, num1, num2) << endl;
	cout << "num1: " << num1 << ' ' << "num2: " << num2 << endl;
} 