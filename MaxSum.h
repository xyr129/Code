#pragma once

//���ܣ����������������
//���磺{1��-2��3��10��-4��7��2��-4}
//�����18

//1����sum�������ͣ�newSum���浱ǰ�ͣ�index�������͵������鿪ʼ�±�
//2�����newSumС�ڵ�ǰֵ��˵����indexΪ��ʼ�±��������֮�Ͳ������ͣ�
//   ����index��sum��newSum
//3�����newSum����sum�������sum

int MaxSum(int* array,int size)
{
	if (NULL == array || size <= 0)
	{
		return -1;
	}

	int sum = array[0];
	int newSum = array[0];
	int index = 0;
	for (int i = 1; i < size; ++i)
	{
		newSum += array[i];
		if (newSum<array[i])
		{
			index = i;
			sum = newSum = array[i];
		}
		else if (newSum>sum)
		{
			sum = newSum;
		}
		else{}
	}
	return sum;
}

void TestMaxSum()
{
	int array[8] = { 1, -2, 3, 10, -4, 7, 2, -6 };
	cout << MaxSum(array, 8) << endl;
}
