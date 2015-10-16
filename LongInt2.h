#ifndef LONGINT2_H
#define LONGINT2_H

#include <iostream>
#include <vector>
#include <string>

const int BASE = 10000;
const int DIGITS = 4;

class LongInt;

std::ostream & operator<<(std::ostream & os, const LongInt & l);


//get the minimum of two values
inline
int min(int x, int y)
{
	return (x < y ? x : y);
}


// get the maximum of two values
inline
int max(int x, int y)
{
	return (x > y ? x : y);
}


// get the abs value of a value
/*
int abs(int x)
{
	return (x < 0 ? -x : x);
}
*/

class LongInt
{
public:
	LongInt(long int x=0); // Get a LongInt from a normal integer
	LongInt(const int x[], int size); // Get a LongInt from an array of integers
	LongInt(const std::string & s); // Get a LongInt from a string
	LongInt(const std::vector<int> & digits_); // Get a LongInt from a std::vector< int >

	// getter methods 
	int operator[](int i) const { return digits_[i]; }
	int & operator[](int i) { return digits_[i]; }
	int size() const { return digits_.size(); }
	int sign() const { return (digits_[0] < 0 ? -1 : 1); }
	

	void add(int i, int val);

	// Comparison Operators
	bool operator==(const LongInt & l) const;
private:
	std::vector< int > digits_;
};



inline 
int digits(int x)
{
	int c = 0;
	do
	{
		x /= 10;
		c += 1;
	} while (x != 0);
	return c;
}

inline
int zero_padding(int x)
{
	int c = digits(x);
	return DIGITS - c;
}

inline 
std::ostream & operator<<(std::ostream & os, const LongInt & l)
{
	int k = l.size()-1;
	if (l.size() == 0)
	{
		os << '0';
		return os;
	}
	if (l[k] < 0)
		os << '-';
	os << abs(l[k]);
	for (int i = k-1; i >= 0; --i)
	{
		for (int j = 0; j < zero_padding(l[i]); ++j)
			os << '0';
		os << abs(l[i]);
		/*
		if (l[i] >= 1000)
		{
			os << l[i];
		}
		else if (l[i] >= 100)
		{
			os << '0' << l[i];
		}
		else if (l[i] >= 10)
		{
			os << "00" << l[i];
		}
		else
		{
			os << "000" << l[i];
		}
		*/
	}
	return os;
}

#endif
