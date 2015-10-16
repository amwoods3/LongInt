
#include <iostream>
#include "LongInt2.h"
#include <cstdlib>
#include <ctime> 
/*
LongInt pow(int base, int exp)
{
	LongInt l(1);
	for (int i = 0; i < exp; ++i)
	{
		l *= base;
	}
	return l;
}

LongInt pow2(int base, int expo)
{
	if (expo == 1)
		return LongInt(base);
	if (expo == 0)
		return LongInt(1);
	else if (expo % 2 == 0)
	{
		LongInt t = pow2(base, expo / 2);
		return t * t;
	}
	else 
	{
		LongInt t = pow2(base, expo / 2);
		return t * t * base;
	}
}

LongInt fac(int k)
{
	LongInt l(1);
	for (int i = 1; i <= k; ++i)
	{
		l *= i;
	}
	return l;
}

LongInt fac2(int k, int b=false)
{
	if (b)
	{

		LongInt m(1);
		int j = 1;
		while (j < k)
		{
			LongInt n(1);
			for (int i = j; i <= k && i <= j + 99; ++i)
			{
				n *= i;
			}
			j += 100;
			m *= n;
		}

		return m;
	}
	else
	{
		LongInt m(1);
		LongInt n(1);
		for (int i = 1; i <= k; ++i)
		{
			if (i % 2 == 0)
				m *= i;
			else
				n *= i;
		}
		return m * n;
	}
}
*/


LongInt random_long()
{
	int length = rand() % 15 + 2;
	LongInt randl(0);
	for (int i = 0; i < length; ++i)
	{
		randl.add(i, rand() % BASE);
	}
	return randl;
}


int main()
{
	int test_case = 0;
	switch
	std::string z;
	std::cin >> z;
	LongInt a(z);
	std::cin >> z;
	LongInt b(z);
	if (a == b) {
		std::cout << a << " and " << b << " are the same value." << std::endl;
	}
	else {
		std::cout << a << " does not equal " << b << std::endl;
	}
	return 0;
}
