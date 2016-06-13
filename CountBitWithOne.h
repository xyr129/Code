#pragma once

//���ܣ�ͳ�ƶ�������1�ĸ���

//��1�����������������㣬����1
//��Ҫ�����������֣���һ���Ǹ�������

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