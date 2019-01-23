/*
********it is the function to raise numbers to a power********
*/
/*This function takes two arguments (the first is a number,
and the second is a power (default is 2)).
This function returns values of the same type as the first argument.
Also this function returns an exception( std::logic_error ) 
in case of overflow of value boundaries.
*/
#include <iostream>
#include <limits>

#ifndef FRAISEPOWER_H
#define FRAISEPOWER_H
//list of functions with parameters that cannot be used
int fRaisePower(short* num, int pow = 2) = delete;
int fRaisePower(unsigned short* num, int pow = 2) = delete;
int fRaisePower(const short* num, int pow = 2) = delete;
int fRaisePower(const unsigned short* num, int pow = 2) = delete;

int fRaisePower(int* num, int pow = 2) = delete;
int fRaisePower(unsigned int* num, int pow = 2) = delete;
int fRaisePower(const int* num, int pow = 2) = delete;
int fRaisePower(const unsigned int* num, int pow = 2) = delete;

int fRaisePower(long* num, int pow = 2) = delete;
int fRaisePower(unsigned long* num, int pow = 2) = delete;
int fRaisePower(const long* num, int pow = 2) = delete;
int fRaisePower(const unsigned long* num, int pow = 2) = delete;

int fRaisePower(long long* num, int pow = 2) = delete;
int fRaisePower(unsigned long long* num, int pow = 2) = delete;
int fRaisePower(const long long* num, int pow = 2) = delete;
int fRaisePower(const unsigned long long* num, int pow = 2) = delete;

int fRaisePower(float* num, int pow = 2) = delete;
int fRaisePower(double* num, int pow = 2) = delete;
int fRaisePower(long double* num, int pow = 2) = delete;
int fRaisePower(const float* num, int pow = 2) = delete;
int fRaisePower(const double* num, int pow = 2) = delete;
int fRaisePower(const long double* num, int pow = 2) = delete;

int fRaisePower(const void* num, int pow = 2) = delete;
int fRaisePower(const char num, int pow = 2) = delete;
int fRaisePower(const char* num, int pow = 2) = delete;
int fRaisePower(const signed char num, int pow = 2) = delete;
int fRaisePower(const signed char* num, int pow = 2) = delete;
int fRaisePower(const unsigned char num, int pow = 2) = delete;
int fRaisePower(const unsigned char* num, int pow = 2) = delete;
int fRaisePower(const wchar_t num, int pow = 2) = delete;
int fRaisePower(const wchar_t* num, int pow = 2) = delete;
int fRaisePower(const char16_t num, int pow = 2) = delete;
int fRaisePower(const char16_t* num, int pow = 2) = delete;
int fRaisePower(const char32_t num, int pow = 2) = delete;
int fRaisePower(const char32_t* num, int pow = 2) = delete;
int fRaisePower(const bool num, int pow = 2) = delete;
int fRaisePower(const std::string num, int pow = 2) = delete;

//in fact, a function template
template < class myTYPE >
myTYPE fRaisePower(myTYPE num, int pow = 2)
{
	if (num == 0)
	{
		return num;
	}
	if (pow < 1)
	{
		throw std::logic_error ("the power is too small");
	}
	if (pow > 700000000)
	{
		throw std::logic_error("the power is too big");
	}
		 
	myTYPE res = 1;
	const myTYPE max = std::numeric_limits<myTYPE>::max();
	std::cout << max << std::endl;
	const myTYPE min = std::numeric_limits<myTYPE>::lowest();
	std::cout << min << std::endl;
	for (int i = 0; i < pow; i++)
	{
		
		res *= num;

		if (num > 0)
		{
			if (res > max || res < 0)
			{
				throw std::logic_error("the result is not in limit");
			}
		}
		else
		{
			if (((i+2)%2) == 0)
			{
				if (res < min || res > 0 )
				{
					throw std::logic_error("the result is not in limit");
				}
			}
			else
			{
				if (res > max || res < 0)
				{
					throw std::logic_error("the result is not in limit");
				}
			}
		}
	}
	return res;
}


#endif // !FRAISEPOWER_H
