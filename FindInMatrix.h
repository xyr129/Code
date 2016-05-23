#pragma once

//��һ��int�Ͷ�ά�����в��Ҹ���ֵx
//���ҵ�����true,���򷵻�false
//����ÿһ���������ҵ�����ÿһ���������µ���

//�Ӷ�ά�������Ͻǿ�ʼ��x���ڵ�ǰλ�õ�ֵ������true
//x���ڵ�ǰλ�õ�ֵ�����м�һ
//�����м�һ
//���мӵ�row�������м���0��û�ҵ��򷵻�false
bool FindInMatrix(const int array[][5], const int row,const int col, const int x)
{
	assert(array);
	assert(col > 0 && row > 0);
	
	int rowIndex = 0;
	int colIndex = col-1;
	while (rowIndex < row && colIndex >= 0)
	{
		if (x == array[rowIndex][colIndex])
		{
			return true;
		}
		if (x>array[rowIndex][colIndex])
		{
			++rowIndex;
		}
		else
		{
			--colIndex;
		}
	}
	return false;
}