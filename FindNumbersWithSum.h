#pragma once

//���ܣ���һ�������������У���ΪS����������

//���� {1��2��4��7��11��15} S:15
//��� 4��11

//�������������м��ߣ���������֮�͵����˵�
//�����һ���������һ���������ΪnewSum
//newSum����S���ȥ���һ���������ϵ����ڶ�����
//newSumС��S���ȥ��һ���������ϵڶ�����
//����򷵻�
//ѭ����������

void NumbersWithSum(int *array, int size, int sum)
{
	assert(array);
	assert(size > 0);

	int newSum = 0;
	int left = 0;
	int right = size - 1;

	while (left < right)
	{
		newSum = array[left] + array[right];
		if (newSum > sum)
		{
			newSum -= array[right];
			--right;
		}
		else if (newSum < sum)
		{
			newSum -= array[left];
			++left;
		}
		else
		{
			cout << "��Ϊ" << sum << "����������" << array[left] << "��" << array[right] << endl;
			return;
		}
	}
	
}

void TestNumbersWithSum()
{
	int array[] = { 1, 2, 4, 7, 11, 15 };
	NumbersWithSum(array, 6, 15);
}