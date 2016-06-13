#pragma once

//���ܣ���%20�滻�ַ����еĿո�

//�ⷨһ����ǰ�������������һ���ո�ͰѺ��沿�����������(O(N^2))
//�ⷨ����ͳ�ƿո�ĸ����������ַ�������(len+count*2)
//        �Ӻ���ǰ����

char* ReplaceBlank(char str[], int maxLen)
{
	assert(str);

	int count = 0;
	int len = 0;
	
	int end = 0;
	while (str[end] != '\0')
	{
		if(' ' == str[end])
		{
			++count;
		}
		++end;
		++len;
	}

	int newLen = len + 2 * count;
	if (newLen > maxLen)
	{
		return str;
	}

	int newEnd = end + 2 * count;

	while (end >= 0)
	{
		if (' ' == str[end])
		{
			str[newEnd--] = '0';
			str[newEnd--] = '2';
			str[newEnd--] = '%';
		}
		else
		{
			str[newEnd--] = str[end];
		}	
		--end;
	}
	return str;
}


void TestReplaceBlank()
{
	char str[] = "how are you";
	cout << ReplaceBlank(str,20) << endl;
}