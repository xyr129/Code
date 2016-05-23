#pragma once

//���ܣ���������˳����ż��λ������ǰ��

//��ʼ״̬��oddָ��ͷ��evenָ��β
//odd�ӵ�ǰλ�ÿ�ʼ����ҵ���һ��������even�ӵ�ǰλ�ÿ�ʼ��ǰ�ҵ���һ��ż��������
//�ظ�����������ֱ���ߵ�odd>even

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
		//������
		while (odd < even && IsEven(array[odd]))
		{
			odd++;
		}
		//��ż��
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

