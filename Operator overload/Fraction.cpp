#include"Header.h"

unsigned int NOD(const int x, const int y)
{
	return (y == 0) ? x : NOD(y, x % y);

}
int Fraction::get_integer() const { return integer; }
int Fraction::get_numerator() const { return  numerator; }
int Fraction::get_denominator() const { return denominator; }

void Fraction::set_integer(int integer) { this->integer = integer; }
void Fraction::set_numerator(int numerator) { this->numerator = numerator; }
void Fraction::set_denominator(int denominator)
{
	this->denominator = denominator;
	if (!denominator)this->denominator = 1;
}

Fraction::operator double()
{
	cout << "Conversion fraction to double\n";
	return integer + (double)numerator / denominator;
}
void Fraction::to_improper()
{
	if (integer)
	{
		numerator = integer * denominator + numerator;
		integer = 0;
	}
}
void Fraction::GetIntPart()
{
	if (!integer)
	{
		integer = double(numerator) / double(denominator);
		numerator %= denominator;
	}
}
void Fraction::reduce()
{
	// translate the number into positive to find the NOD 
	int nod = NOD(numerator > 0 ? numerator : numerator * -1, denominator > 0 ? denominator : denominator * -1);
	denominator /= nod;
	numerator /= nod;
}
void Fraction::Print()
{
	cout << endl << this << endl;
	cout << "decimal: \n" << integer + (double)numerator / denominator << endl;
	cout << "fraction: \n";
	cout << integer;

	if (numerator)
	{
		cout << " + (" << double(numerator) << '/' << denominator << ')';
	}
	cout << endl << endl;
}

Fraction operator-(Fraction right, Fraction left)
{
	cout << "\noperator -" << endl;

	left.to_improper();
	right.to_improper();
	// if and else for reduce work 

	// if right  & left operand denominotor not equal 
	if (left.get_denominator() != right.get_denominator())
	{
		Fraction temp(0, (right.get_numerator() * left.get_denominator()) - (left.get_numerator() * right.get_denominator()), right.get_denominator() * left.get_denominator());
		return temp;
	}

	// if right & left denominotor equal 
	else
	{
		Fraction temp(left.get_numerator() - right.get_numerator(), left.get_denominator());
		return temp;
	}

}
Fraction operator*(Fraction right, Fraction left)
{
	cout << "operatorn *" << endl;
	left.to_improper();
	right.to_improper();
	Fraction temp(right.get_numerator() * left.get_numerator(), right.get_denominator() * left.get_denominator());
	return temp;
}
Fraction operator/(Fraction right, Fraction left)
{
	left.to_improper();
	right.to_improper();

	Fraction temp(right.get_numerator() * left.get_denominator(), right.get_denominator() * left.get_numerator());
	return temp;
}

Fraction::Fraction (int integer, int numerator, int denominator)
{
	if (integer && !numerator && denominator == 1)// if in fraction only has integer ( (int)a = 0 + (a / 1)  )
	{
		this->numerator = integer;
		this->integer = 0;
		this->denominator = 1;
	}
	else
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
	}
	cout << "Constructor: " << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	cout << "SingleArgConstructor:\t" << this << endl;
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
}
Fraction::Fraction(double decimal)
{
	cout << "Conversion double to fraction: " << this << endl; ;
	integer = decimal;
	decimal -= integer;
	decimal *= 100000000;
	numerator = decimal;
	denominator = 100000000;
	reduce();
	/*while (this->numerator / i != decimal);			//failed code(
{
	numerator = decimal * i;
	i *= 10;
}
this->denominator = i;*/
}
Fraction::~Fraction() { cout << "destructor:\t" << this << endl; }
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefConstructor:\t" << this << endl;
}

Fraction& Fraction::to_improper(int)
{
	if (integer)
	{
		numerator = integer * denominator + numerator;
		integer = 0;
	}
	return *this;
}
Fraction& Fraction::GetIntPart(int)
{
	if (!integer)
	{
		integer = double(numerator) / denominator;
		numerator %= denominator;
	}
	return *this;
}
Fraction& Fraction::reduce(int)
{
	// translate the number into positive to find the NOD 
	int nod = NOD(numerator > 0 ? numerator : numerator * -1, denominator > 0 ? denominator : denominator * -1);
	denominator /= nod;
	numerator /= nod;
	return *this;
}

bool operator<=(const Fraction& right, const Fraction& left)
{
	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) <= left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? 1 : 0;
}
bool operator> (const Fraction& right, const Fraction& left)
{
	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) > left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? 1 : 0;
}
bool operator>=(const Fraction& right, const Fraction& left)
{
	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) >= left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? 1 : 0;
}
bool operator==(const Fraction& right, const Fraction& left)
{
	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) == left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? 1 : 0;
}
bool operator!=(const Fraction& right, const Fraction& left)
{
	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) != left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? 1 : 0;
}

Fraction& Fraction:: operator= (const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment: " << this << endl;
	return *this;
}
Fraction& Fraction:: operator*=(Fraction other)
{
	this->reduce();
	this->to_improper();
	other.reduce();
	other.to_improper();

	this->numerator *= other.numerator;
	this->denominator *= other.denominator;
	return *this;
}
Fraction& Fraction:: operator/=(Fraction other)
{
	this->reduce();
	this->to_improper();
	other.reduce();
	other.to_improper();

	this->numerator *= other.denominator;
	this->denominator *= other.numerator;
	return *this;
}
Fraction& Fraction:: operator+=(Fraction other)
{
	this->reduce();
	this->to_improper();
	other.reduce();
	other.to_improper();

	this->numerator = this->numerator * other.denominator + this->denominator * other.numerator;
	this->denominator *= other.denominator;
	return *this;
}
Fraction& Fraction:: operator-=(Fraction other)
{
	this->reduce();
	this->to_improper();
	other.reduce();
	other.to_improper();

	this->numerator = this->numerator * other.denominator - this->denominator * other.numerator;
	this->denominator *= other.denominator;
	return *this;
}
Fraction operator+(Fraction right, Fraction left)
{
	cout << "\noperator +\t" << endl;
	left.to_improper();
	right.to_improper();

	if (left.get_denominator() != right.get_denominator())
	{
		Fraction temp(0, (right.get_numerator() * left.get_denominator()) + (left.get_numerator() * right.get_denominator()), right.get_denominator() * left.get_denominator());
		return temp;
	}
	else
	{
		Fraction temp(left.get_numerator() + right.get_numerator(), left.get_denominator());
		return temp;
	}

}
std::ostream& operator<<(std::ostream& os, Fraction& obj)
{
	obj.Print();
	return os;
}

Fraction& Fraction:: operator++()		
{
	integer++;
	return *this;
}
Fraction  Fraction:: operator++(int)		// Postfix
{
	Fraction buffer = *this;
	integer++;
	return buffer;
}
Fraction& Fraction:: operator--()			//Prefix
{
	integer--;
	return *this;
}
Fraction  Fraction:: operator--(int)		// Postfix
{
	Fraction buffer = *this;
	integer--;
	return buffer;
}
Fraction& Fraction:: operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}

 

#ifdef IMPLEMENTATION_OPTIONS_COMPARE

bool Fraction:: operator<=(const Fraction& other)const
{
	return (this->integer + double(this->numerator / this->denominator)) <= (other.integer + double(other.numerator / other.denominator)) ? 1 : 0;
}
bool Fraction::  operator<(const Fraction& other)const
{
	return (this->integer + double(this->numerator / this->denominator)) < (other.integer + double(other.numerator / other.denominator)) ? 1 : 0;
}
bool Fraction:: operator> (const Fraction& other)const
{
	return (this->integer + double(this->numerator / this->denominator)) > (other.integer + double(other.numerator / other.denominator)) ? 1 : 0;
}
bool Fraction:: operator>=(const Fraction& other)const
{
	return (this->integer + double(this->numerator / this->denominator)) >= (other.integer + double(other.numerator / other.denominator)) ? 1 : 0;
}
bool Fraction:: operator==(const Fraction& other)const
{
	return (this->integer + double(this->numerator / this->denominator)) == (other.integer + double(other.numerator / other.denominator)) ? 1 : 0;
}
bool Fraction:: operator!=(const Fraction& other)const
{
	return (this->integer + double(this->numerator / this->denominator)) != (other.integer + double(other.numerator / other.denominator)) ? 1 : 0;
}
#else

bool Fraction:: operator< (Fraction& other)
{
	return (double(*this) < double(other)) ? 1 : 0;
}

bool Fraction:: operator<= (Fraction& other)
{
	return (double(*this) <= double(other)) ? 1 : 0;
}

bool Fraction:: operator> (Fraction& other)
{
	return (double(*this) > double(other)) ? 1 : 0;
}

bool Fraction:: operator >= (Fraction& other)
{
	return (double(*this) >= double(other)) ? 1 : 0;
}

bool Fraction:: operator == (Fraction& other)
{
	return (double(*this) == double(other)) ? 1 : 0;
}

bool Fraction::operator != (Fraction& other)
{
	return (double(*this) != double(other)) ? 1 : 0;
}

#endif // IMPLEMENTATION_OPTIONS_COMPARE
/*
bool operator< (Fraction& right, Fraction& left) //  It allso possible with the rest just change operator and comprasion in return
{
	return (double(right) < double(left)) ? 1 : 0;
}
*/