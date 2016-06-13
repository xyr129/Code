#pragma once

//���ܣ���ΪS������������������(���ٰ���������)
 
//���� 9
//��� {2,3,4}��{4,5}

//����������еĿ�ʼֵ��������ܳ���(1+S)/2
//�ӿ�ʼֵ������һֱ�ӵ��ʹ���S���ı俪ʼֵ(��1)
//����ӵ�����S��ȣ���ӡ��ǰ����
//�ظ�����������ֱ����ʼֵ����(1+S)/2

void SequenceWithSum(int sum)
{
	if (sum < 3)
	{
		cout << "û������Ҫ�������" << endl;
	}

	int limit = (1 + sum) / 2;
	int start = 1;
	int end = 2;
	int newSum = start + end;
	while (start < limit)
	{
		if (newSum > sum)
		{
			start++;
			end = start + 1;
			newSum = start + end;
		}
		else if (newSum < sum)
		{
			end++;
			newSum += end;
		}
		else
		{
			for (int i = start; i <= end; ++i)
			{
				cout << i << ',';
			}
			cout << endl;
			start++;
			end = start + 1;
			newSum = start + end;
		}
	}
}

void TestSequenceWithSum()
{
	cout << "��Ϊ9�����У�" << endl;
	SequenceWithSum(9);
	cout << "��Ϊ15�����У�" << endl;
	SequenceWithSum(15);
}
