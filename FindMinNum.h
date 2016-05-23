#pragma once

//查找旋转数组的最小数字
//例如原数组(以递增为例) 0 1 2 3 4 5 6 7 8 9
//旋转之后 5 6 7 8 9 0 1 2 3 4

//如果初始区间为递增，直接返回第一个数
//否则，使用二分查找，每次选择非递增的那一半区间
//当所选的非递增区间只有两个数时，第二个即为所要找的最小数
int FindMinNum(int* array, int size)
{
	assert(array);
	assert(size > 0);

	int left = 0; 
	int right = size - 1;
	if (array[left] < array[right])
	{
		return array[left];
	}
	while (left < right)
	{
		if (right - left == 1)
		{
			return array[right];
		}
		int mid = left + (right - left) / 2;
		if (array[left] > array[mid])
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
}