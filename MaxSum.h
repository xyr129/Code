#pragma once

//功能：连续子数组的最大和
//例如：{1，-2，3，10，-4，7，2，-4}
//结果：18

//1、用sum保存最大和，newSum保存当前和，index保存最大和的子数组开始下标
//2、如果newSum小于当前值，说明以index为开始下标的子数组之和不是最大和，
//   更新index、sum、newSum
//3、如果newSum大于sum，则更新sum

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
