#include "LongInt2.h"

int to_int(std::string s)
{
	int ret = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		ret += s[i] - '0';
		ret *= 10;
	}
	return ret /= 10;
}

/*
Here are the Constructors for the LongInt 
*/
LongInt::LongInt(long int x) {
	do {
			digits_.push_back(x % BASE);
			x /= BASE;
	} while (x != 0);
}


LongInt::LongInt(const int x[], int size)
{
	bool negative = x[0] < 0;
	for (int i = 0; i < size; ++i) {
		if ((x[i] < BASE && x[i] >= 0 && !negative) || (x[i] < 0 && x[i] > -BASE && negative))
			digits_.push_back(x[i]);
	}
}


LongInt::LongInt(const std::string & s) {
	bool negative = false;
	int start = 0;
	for (; s[start] == '+' || s[start] == '-'; ++start) {
		if (s[start] == '-')
			negative = !negative;
	}

	for (int i = s.size() - 1; i >= start; i -= 4) {
		if (i >= 4 + start) {
			int k = to_int(s.substr(i-3, 4));
			digits_.push_back((negative ? -k : k));
		}
		else {
			int k = to_int(s.substr(start, i+1));
			digits_.push_back((negative ? -k : k));
		}
	}
}

LongInt::LongInt(const std::vector< int > & x) {
	bool negative = x[0] < 0;
	for (int i = 0; i < x.size(); ++i) {
		if ((x[i] < BASE && x[i] >= 0 && !negative) || (x[i] < 0 && x[i] > -BASE && negative))
			digits_.push_back(x[i]);
	}
}

/*
 End Constructors
*/


/*
 Here are the comparison operators
*/

bool LongInt::operator==(const LongInt & l) const {
	if (sign() != l.sign()) // sign is the most important for determining equality
		return false;
	if (size() != l.size()) // size is the next most important thing
		return false;
	for (int i = 0; i < size(); ++i)
	{
		if (digits_[i] != l[i])
			return false;
	}
	return true;
}

/*
 End the Comparison Operators
*/


void LongInt::add(int i, int val) {
	if (i >= size()) {
		digits_.push_back(val);
	}
	else {
		digits_[i] += val;
	}
	return;
}