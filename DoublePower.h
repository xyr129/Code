#pragma once

//���ܣ���ֵ�������η�

//1������Ϊ�㣨double��������ıȽϣ�
//2��ָ��Ϊ��
//3��ָ��Ϊ�� 

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
