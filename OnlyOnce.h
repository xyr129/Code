#pragma once

//���ܣ�һ�����н�������ֻ����һ�ε����֣��������ֳɶԳ���

//�����������������򣬵õ��Ľ��������ֻ����һ�����ֵ����
//�ҵ��������������Ƶ�һ��1��λ������������һ����ͬ��λ��
//�������е�������λ��1����0�ֳ�����

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
	cout << "�Ƿ����ֻ����һ�ε�����: " << OnlyOnce(array, 10, num1, num2) << endl;
	cout << "num1: " << num1 << ' ' << "num2: " << num2 << endl;
} 