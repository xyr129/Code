#pragma once

//功能：在一组递增排序的数中，和为S的两个数字

//输入 {1，2，4，7，11，15} S:15
//输出 4和11

//从数组两端往中间走，根据两端之和调整端点
//数组第一个数和最后一个数相加作为newSum
//newSum大于S则减去最后一个数，加上倒数第二个数
//newSum小于S则减去第一个数，加上第二个数
//相等则返回
//循环上述操作

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
			cout << "和为" << sum << "的两个数：" << array[left] << "和" << array[right] << endl;
			return;
		}
	}
	
}

void TestNumbersWithSum()
{
	int array[] = { 1, 2, 4, 7, 11, 15 };
	NumbersWithSum(array, 6, 15);
}