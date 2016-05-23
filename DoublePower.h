#pragma once

//功能：数值的整数次方

//1、基数为零（double类型与零的比较）
//2、指数为零
//3、指数为负 

double DoublePower(double base, int exponent)
{
	if (base<0.000001 && base>-0.000001)
	{
		return 0.0;
	}
	if (exponent == 0 || base == 1.0)
	{
		return 1.0;
	}
	if (base == -1)
	{
		return (exponent % 2 == 0) ? 1.0 : -1.0;
	}

	double result = 1.0;
	bool symbol = true;
	if (exponent < 0)
	{
		symbol = false;
		exponent = 0 - exponent;
	}
	while (exponent--)
	{
		result *= base;
	}
	if (symbol == false)
	{
		result = 1.0 / result;
	}
	return result;
}
