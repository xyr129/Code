#pragma once

//���ܣ�˳ʱ���ӡһ��m*n�ľ���

//ÿһȦ����ʼ��Ϊ(start,start)��start�ĳ�ʼֵΪ0
//���ĸ����裺
//1���������Ҵ�ӡһ��
//2���������´�ӡһ��(�����㵱ǰ״̬����ʼ��С����ֹ��)
//3�����������ӡһ��(�����㵱ǰ״̬����ʼ��С����ֹ��)
//4���������ϴ�ӡһ��(�����㵱ǰ״̬����ʼ��+1С����ֹ��)

void PrintMatrix(vector<vector<int>>& matrix)
{
	if (!matrix.empty())
	{
		int rows = matrix.size();
		int cols = matrix[0].size();
		int start = 0;
		int endRow = rows - 1;
		int endCol = cols - 1;
		while (2*start<rows && 2*start<cols)
		{
			//1����-->��
			for (int index = start; index <= endCol; ++index)
			{
				cout << matrix[start][index] << " ";
			}
			//2����-->��
			if (start < endRow)
			{
				for (int index = start+1; index <= endRow; ++index)
				{
					cout << matrix[index][endCol] << " ";
				}
			}
			//3����-->��
			if (start < endCol)
			{
				for (int index = endCol - 1; index >= start; --index)
				{
					cout << matrix[endRow][index] << " ";
				}
			}
			//4����-->��
			if (start < endRow - 1)
			{
				for (int index = endRow - 1; index>start; --index)
				{
					cout << matrix[index][start] << " ";
				}
			}
			++start;
			--endCol;
			--endRow;
		}
	}
}

void TestPrintMatrix()
{
	int array[4][5] = { { 1, 6, 9, 13, 15 }, { 2, 7, 10, 14, 16 }, { 3, 8, 12, 15, 20 }, { 6, 17,18, 22, 25 } };
	vector<vector<int>> matrix;
	matrix.push_back(vector<int>());
	matrix.push_back(vector<int>());
	matrix.push_back(vector<int>());
	matrix.push_back(vector<int>());

	for (int row = 0; row < 4; ++row)
	{
		
		for (int col = 0; col < 5; ++col)
		{
			matrix[row].push_back(array[row][col]);
		}
	}
	PrintMatrix(matrix);
}