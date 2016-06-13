#pragma once

//¹¦ÄÜ£º×óĞı×Ö·û´®

//ABCDEF×óĞıÁ½Î»->CDEFAB

void _Reverse(char* begin, char* end)
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

char* Rotate_L(char* str, int n)
{
	assert(str);

	int len = strlen(str);
	if (n > 0 && len > 0 && n < len)
	{
		char* begin = str;
		char* part = str + n - 1;
		char* end = str + len - 1;
		_Reverse(begin, part);
		_Reverse(part + 1, end);
		_Reverse(begin, end);
	}

	return str;
}

void TestRotate_L()
{
	char str[] = "ABCDEF";
	cout << Rotate_L(str, 2) << endl;
}