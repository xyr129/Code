#pragma once

//功能：以单词为最小单位翻转字符串

//例如：
//翻转前->I am a student
//翻转后->student a am I

//先翻转整个字符串
//再翻转每个单词

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

	//翻转每个单词
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