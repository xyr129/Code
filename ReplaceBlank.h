#pragma once

//功能：用%20替换字符串中的空格

//解法一：从前往后遍历，碰到一个空格就把后面部分整体向后移(O(N^2))
//解法二：统计空格的个数，调整字符串长度(len+count*2)
//        从后往前复制

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