#pragma once

//���ܣ���ӡ��1������nλʮ������
//���磬����3����˳���ӡ1��999

//��������ĺϷ����ж�
//�����Ǵ���
void PrintToMaxNum(int n)
{
	if (n <= 0)
	{
		cout << "Input error!" << endl;
	}
	long long maxNum = 9;
	long long i = 1;
	while (i++ < n)
	{
		maxNum = maxNum * 10 + 9;
	}
	i = 1;
	while (i <= maxNum)
	{
		cout << i << " ";
		++i;
	}
	cout << endl;
}

//���Ǵ���
void PrintToMaxNum1();