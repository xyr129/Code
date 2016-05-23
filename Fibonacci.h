#pragma once

//ì³²¨ÄÇÆõÊıÁĞ
int Fib_R(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return Fib_R(n - 1) + Fib_R(n - 2);
}

int Fib_NR1(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	int fib1 = 0;
	int fib2 = 1;
	int fib = 0;
	for (int i = 0; i <= n; i++)
	{
		fib = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib;
	}
	return fib;
}

long long Fib_NR2(const size_t n)
{
	if (0 == n)
	{
		return 0;
	}
	if (1 == n)
	{
		return 1;
	}
	long long fib1 = 0;
	long long fib2 = 1;
	long long fib = 0;
	for (size_t i = 0; i < n; i++)
	{
		fib = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib;
	}
	return fib;
}