#pragma once

//功能：在排序数组中统计K出现的次数
//时间复杂度O(logN)

//用二分查找得到第一个K和最后一个K的下标
//次数等于差值加一
//FIRST表示找第一个K，LAST表示找最后一个K

enum Which
{
	FIRST,
	LAST,
};

int GetIndex(Which& wh, int* array, int k, int size)
{
	if (NULL == array || size <= 0)
	{
		return -1;
	}

	//
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		
		//找第一个k
		if (FIRST == wh)
		{
			if (k==array[mid])
			{
				if (mid - 1 < 0 || array[mid - 1] < k)
					return mid;
				else
					right = mid - 1;
			}
			else
			{
				if (mid-1>0 && array[mid - 1]>k)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
		}

		//找最后一个k
		else
		{
			if (k == array[mid])
			{
				if (mid + 1 >=size || array[mid + 1] > k)
					return mid;
				else
					left = mid + 1;
			}
			else
			{
				if (mid+1<size && array[mid + 1]>k)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
		}
	}
	return -1;
}

int TimesKInSortArray(int* array,int size,int k)
{
	if (NULL == array || size <= 0)
	{
		return 0;
	}
	Which f = FIRST;
	Which l = LAST;
	int f_index = GetIndex(f, array, k, size);
	int l_index = GetIndex(l, array, k, size);
	return l_index - f_index + 1;

}

void TestTimesInSortArray()
{
	int array[10] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
	cout << TimesKInSortArray(array, 9, 2) << endl;
	
	int array1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 2 };
	cout << TimesKInSortArray(array1, 9, 2) << endl;

}