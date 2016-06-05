#pragma once

//功能：顺时针打印一个m*n的矩阵

//每一圈的起始点为(start,start)，start的初始值为0
//分四个步骤：
//1、从左往右打印一行
//2、从上往下打印一列(需满足当前状态的起始行小于终止行)
//3、从右往左打印一行(需满足当前状态的起始列小于终止列)
//4、从下往上打印一列(需满足当前状态的起始行+1小于终止行)

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
			//1、左-->右
			for (int index = start; index <= endCol; ++index)
			{
				cout << matrix[start][index] << " ";
			}
			//2、上-->下
			if (start < endRow)
			{
				for (int index = start+1; index <= endRow; ++index)
				{
					cout << matrix[index][endCol] << " ";
				}
			}
			//3、右-->左
			if (start < endCol)
			{
				for (int index = endCol - 1; index >= start; --index)
				{
					cout << matrix[endRow][index] << " ";
				}
			}
			//4、下-->上
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