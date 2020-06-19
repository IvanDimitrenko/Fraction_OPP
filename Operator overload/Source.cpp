#include<iostream>
#include<math.h>

using std::cout;
using std::cin;
using std::endl;


#define GET_SET
#define IMPLEMENTATION_OPTIONS_COMPARE
unsigned int NOD(const int x, const int y)
{
	return (y == 0) ? x : NOD(y, x % y);
}
class Fraction
{
private:
	int	integer , denominator , numerator;
public:

#ifdef GET_SET
	//	 get
	int get_integer() const { return integer; }
	int get_numerator() const { return  numerator; }
	int get_denominator() const { return denominator; }

	//   Set
	void set_integer(int integer) { this->integer = integer; }
	void set_numerator(int numerator) { this->numerator = numerator; }
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
		if (!denominator)this->denominator = 1;
	}
#endif // GET_SET

	//   Constructor								
	Fraction(int integer, int numerator, int denominator)
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
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		cout << "SingleArgConstructor:\t" << this << endl;
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction(double decimal)
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
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	~Fraction() { cout << "destructor:\t" << this << endl; }

	//   Methods
	void to_improper();
	void GetIntPart();
	void reduce();
	void Print();

	//  Overload methods
	Fraction& to_improper(int);
	Fraction& GetIntPart(int);
	Fraction& reduce(int);

	//  Operator overload
	Fraction& operator= (const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}
	Fraction& operator*=(Fraction other)
	{
		this->reduce();
		this->to_improper();
		other.reduce();
		other.to_improper();

		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return *this;
	}
	Fraction& operator/=(Fraction other)
	{
		this->reduce();
		this->to_improper();
		other.reduce();
		other.to_improper();

		this->numerator *= other.denominator;
		this->denominator *= other.numerator;
		return *this;
	}
	Fraction& operator+=(Fraction other)
	{
		this->reduce();
		this->to_improper();
		other.reduce();
		other.to_improper();

		this->numerator = this->numerator * other.denominator + this->denominator * other.numerator;
		this->denominator *= other.denominator;
		return *this;
	}
	Fraction& operator-=(Fraction other)
	{
		this->reduce();
		this->to_improper();
		other.reduce();
		other.to_improper();

		this->numerator = this->numerator * other.denominator - this->denominator * other.numerator;
		this->denominator *= other.denominator;
		return *this;
	}

	Fraction& operator++()			//Prefix
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)		// Postfix
	{
		Fraction buffer = *this;
		integer++;
		return buffer;
	}

	Fraction& operator--()			//Prefix
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)		// Postfix
	{
		Fraction buffer = *this;
		integer--;
		return buffer;
	}

	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator( denominator);
		return *this;
	}

	// Ñomparison operators example in class
#ifdef IMPLEMENTATION_OPTIONS_COMPARE

	bool operator< (const Fraction& other)const
	{
		return (this->integer + double(this->numerator / this->denominator)) < (other.integer + double(other.numerator / other.denominator)) ? 1 : 0;
	}
	bool operator<=(const Fraction& other)const
	{
		return (this->integer + double(this->numerator / this->denominator)) <= (other.integer + double(other.numerator / other.denominator)) ? 1 : 0;
	}
	bool operator> (const Fraction& other)const
	{
		return (this->integer + double(this->numerator / this->denominator)) > (other.integer + double(other.numerator / other.denominator)) ? 1 : 0;
	}
	bool operator>=(const Fraction& other)const
	{
		return (this->integer + double(this->numerator / this->denominator)) >= (other.integer + double(other.numerator / other.denominator)) ? 1 : 0;
	}
	bool operator==(const Fraction& other)const
	{
		return (this->integer + double(this->numerator / this->denominator)) == (other.integer + double(other.numerator / other.denominator)) ? 1 : 0;
	}
	bool operator!=(const Fraction& other)const
	{
		return (this->integer + double(this->numerator / this->denominator)) != (other.integer + double(other.numerator / other.denominator)) ? 1 : 0;
	}
#else

	bool operator< (Fraction& other)
	{
		return (double(*this) < double(other)) ? 1 : 0;
	}
	bool operator<= (Fraction& other)
	{
		return (double(*this) <= double(other)) ? 1 : 0;
	}
	bool operator> (Fraction& other)
	{
		return (double(*this) > double(other)) ? 1 : 0;
	}
	bool operator >= (Fraction& other)
	{
		return (double(*this) >= double(other)) ? 1 : 0;
	}
	bool operator == (Fraction& other)
	{
		return (double(*this) == double(other)) ? 1 : 0;
	}
	bool operator != (Fraction& other)
	{
		return (double(*this) != double(other)) ? 1 : 0;
	}

#endif // IMPLEMENTATION_OPTIONS_COMPARE

	
	operator double()
	{
		cout << "Conversion fraction to double\n";
		return integer + (double)numerator / denominator;
	}
};


Fraction operator+(Fraction right, Fraction left);
Fraction operator-(Fraction right, Fraction left);
Fraction operator*(Fraction right, Fraction left);
Fraction operator/(Fraction right, Fraction left);

bool operator<(const Fraction& right, const Fraction& left);
bool operator<=(const Fraction& right, const Fraction& left);
bool operator> (const Fraction& right, const Fraction& left);
bool operator>=(const Fraction& right, const Fraction& left);
bool operator!=(const Fraction& right, const Fraction& left);
bool operator==(const Fraction& right, const Fraction& left);

void main()
{
	Fraction A(3.3);
	A.Print();
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

bool operator< (Fraction& right, Fraction& left) //  It allso possible with the rest just change operator and comprasion in return
{
	return (double(right) < double(left)) ? 1 : 0;
}
bool operator< (Fraction& right, Fraction& left)
{
	(
		right.get_integer() + double(right.get_numerator() / right.get_denominator())
		<
		left.get_integer() + double(left.get_numerator() / left.get_denominator())
		? 1 : 0);
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

std::ostream& operator<<(std::ostream& os, Fraction& obj)
{
	obj.Print();
	return os;
}
