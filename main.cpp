
#include <iostream>
#include "LongInt2.h"
#include <cstdlib>
#include <ctime> 

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
