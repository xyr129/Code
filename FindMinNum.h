#pragma once

//������ת�������С����
//����ԭ����(�Ե���Ϊ��) 0 1 2 3 4 5 6 7 8 9
//��ת֮�� 5 6 7 8 9 0 1 2 3 4

//�����ʼ����Ϊ������ֱ�ӷ��ص�һ����
//����ʹ�ö��ֲ��ң�ÿ��ѡ��ǵ�������һ������
//����ѡ�ķǵ�������ֻ��������ʱ���ڶ�����Ϊ��Ҫ�ҵ���С��
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