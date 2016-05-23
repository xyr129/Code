#pragma once

//在一个int型二维数组中查找给定值x
//若找到返回true,否则返回false
//数组每一行由左至右递增，每一列由上至下递增

//从二维数组右上角开始，x等于当前位置的值，返回true
//x大于当前位置的值，则行加一
//否则，列减一
//当行加到row，或者列减到0，没找到则返回false
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