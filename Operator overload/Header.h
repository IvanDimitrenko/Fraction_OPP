#pragma once
#include<iostream>
#include<math.h>

using std::cout;
using std::cin;
using std::endl;

#define IMPLEMENTATION_OPTIONS_COMPARE

class Fraction
{
private:
	int	integer,
		denominator,
		numerator;
public:

	Fraction(int integer);
	Fraction(int integer, int numerator, int denominator);
	Fraction(int numerator, int denominator);
	Fraction(double decimal);
	Fraction();
	~Fraction();

	Fraction& operator= (const Fraction& other);
	Fraction& operator*=(Fraction other);
	Fraction& operator-=(Fraction other);
	Fraction& operator/=(Fraction other);
	Fraction& operator+=(Fraction other);


	//   Methods
	void to_improper();
	void GetIntPart();
	void reduce();
	void Print();

	//  Overload methods
	Fraction& to_improper(int);
	Fraction& GetIntPart(int);
	Fraction& reduce(int);

	void set_denominator(int denominator);
	void set_numerator(int numerator);
	void set_integer(int integer);

	int get_integer() const;
	int get_numerator() const;
	int get_denominator() const;
	operator double();

	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
	Fraction& operator()(int integer, int numerator, int denominator);
#ifdef IMPLEMENTATION_OPTIONS_COMPARE


	bool operator <= (const Fraction& other)const;

	bool operator < (const Fraction& other)const;

	bool operator > (const Fraction& other)const;

	bool  operator >= (const Fraction& other)const;

	bool operator == (const Fraction& other)const;

	bool operator != (const Fraction& other)const;

#else

	bool  operator< (Fraction& other);

	bool  operator<= (Fraction& other);

	bool operator >  (Fraction& other);

	bool  operator >= (Fraction& other);

	bool  operator == (Fraction& other);

	bool operator != (Fraction& other);
#endif // IMPLEMENTATION_OPTIONS_COMPARE

};
