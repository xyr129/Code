#pragma once

//���ܣ��Ե���Ϊ��С��λ��ת�ַ���

//���磺
//��תǰ->I am a student
//��ת��->student a am I

//�ȷ�ת�����ַ���
//�ٷ�תÿ������

void Reverse(char* begin, char* end)
{
	assert(begin);
	assert(end);
	while (begin < end)
	{
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
		
		++begin;
		--end;
	}
}

char* ReverseWords(char* str)
{
	assert(str);

	char* begin = str;
	char* end = str;
	while (*end)
	{
		end++;
	}
	Reverse(begin, --end);

	//��תÿ������
	begin = str;
	while (*begin != '\0')
	{
		while (*begin == ' ')
		{
			++begin;
		}

		end = begin;
		while (*end != ' ' && *end != '\0')
		{
			++end;
		}
		Reverse(begin, --end);

		begin = ++end;
	}
	return str;
}

void TestReverseWords()
{
	char str[] = "I am a student";
	cout << ReverseWords(str) << endl;
}