#define _CRT_SECURE_NO_WARNINGS  //for strtok
#include <iostream>
using namespace std;
using std::cout;
using std::cin;

class Fraction;   //Объявление класса 
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//		Constructors:

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Default constructor:" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy constructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//		Operators:

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy Assignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator *=(const Fraction other)
	{
		return *this = *this * other;
	}
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

	//				Type-cast operators:
	operator int()const
	{
		return integer;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//		Methods:
	void print()const
	{
		if (integer)cout << integer;
		if (integer && numerator) cout << "(";
		if (numerator)cout << numerator << "/" << denominator;
		if (integer && numerator) cout << ")";
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}
	Fraction & to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction & to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()    //Переворачивает дробь
	{
		to_improper();
		/*int buffer = numerator;
		numerator = denominator;
		denominator = buffer;
		return *this;*/
		return Fraction(denominator, numerator);
	}
};

Fraction operator*( Fraction left,  Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	);*/
	return  (left * right.inverted());
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction sum
	(
		(left.get_numerator() * right.get_denominator()) +
		(right.get_numerator() * left.get_denominator()),
		(left.get_denominator() * right.get_denominator())
	);	
	sum.to_proper();
	return sum;*/
	return Fraction
	(left.get_numerator() * right.get_denominator() + 
		right.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return	Fraction 
	(
		(left.get_numerator() * right.get_denominator()) -
		(right.get_numerator() * left.get_denominator()),
		(left.get_denominator() * right.get_denominator())
	);
}
bool operator ==(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator());*/
	return (double)left == (double)right;
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator >(const Fraction& left, const Fraction& right)
{
	return (double)left > (double)right;
}
bool operator <(const Fraction& left, const Fraction& right)
{
	return (double)left < (double)right;
}
bool operator >=(const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;  //больше или равно
	return !(left < right);  //Больше или равно это не меньше.
}
bool operator <=(const Fraction& left, const Fraction right)
{
	return !(left > right);
}
ostream& operator << (ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_integer()&& obj.get_numerator())os << "(";
	if (obj.get_numerator())os << obj.get_numerator() << "/" << obj.get_denominator();
	if (obj.get_integer()&& obj.get_numerator()) os << ")";
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	return os;
}
istream& operator >>(istream& is, Fraction& obj)
{
	/*int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/

	const int n = 32;
	char buffer[n] = {};
	char delimiters[] = "(/) +";
	char* number[5] = {};
	cin.getline(buffer, n);
	int i = 0;
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters), i++)
	{
		number[i] = pch;
	}
	//for (int i = 0; i < 3; i++)cout << number[i] << "/t"; cout << endl;
	//cout << buffer << endl;
	switch (i)
	{
	case 1:obj.set_integer(atoi(number[0])); break;
	case 2:
		obj.set_numerator(atoi(number[0]));
		obj.set_denominator(atoi(number[1]));
		break;
	case 3:
		obj.set_integer(atoi(number[0]));
		obj.set_numerator(atoi(number[1]));
		obj.set_denominator(atoi(number[2]));
		break;
	default: cout << "Error" << endl;
	}
	return is;
}

//#define CONSTRUCTORS_CHECK 
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPOUND_ASSIGNMENT_CHECK
//#define OPTIMISATION_CHECK
//#define TYPE_CONVERSIONS
//#define TYPE_CONVERSIONS_HOMEWORK
//#define COMPARISON_OPERATORS
//#define COUT_CHECK
#define INPUT_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();
	Fraction B = 3;
	B.print();
	Fraction C(0, 3, 4);
	C.print();
	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();
	Fraction F;
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();
	Fraction B(3, 4, 5);
	B.print();
	Fraction C = A * B;
	cout << "Умножение: \t";
	C.print();

	Fraction Z = A / B;
	cout << "Деление: \t";
	Z.print();
	/*for (Fraction i(1, 4); i.get_integer() < 10; ++i)
	{
		i.print();
	}
	cout << "----------------------------------------------------------" << endl;
	for (Fraction i(1, 4); i.get_integer() > -10; --i)
	{
		i.print();
	}*/
	Fraction D = A + B;		//(A + B).print();  - можно написать сложение так
	cout << "Сложение: \t";
	D.print();
	Fraction E = A - B;
	cout << "Вычитание: \t";
	E.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPOUND_ASSIGNMENT_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	A *= B;				// Неявный вызов оператора
	//A.operator*=(B);		//Явный вызов оператора 
	cout << "Operator '*=':\t";
	A.print();
#endif // COPOUND_ASSIGNMENT_CHECK

#ifdef OPTIMISATION_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	cout << "\n--------------------------------------\n";
	Fraction C = A * B;
	cout << "\n--------------------------------------\n";
	C.print();
#endif // OPTIMISATION_CHECK

#ifdef TYPE_CONVERSIONS
	Fraction A = (Fraction)5;  //From int to Fraction
	A.print();
	Fraction B;
	B = (Fraction)3;
	B.print();

	int b = B;
	cout << b << endl;
#endif // TYPE_CONVERSIONS
		
#ifdef TYPE_CONVERSIONS_HOMEWORK
	//Task 1:
	Fraction A(2, 3, 4);
	double a = A;
	cout << a << endl;
	
	//Task 2:
	/*double b = 3.14;
	Fraction B = b;
	B.print();*/
#endif // TYPE_CONVERSIONS_HOMEWORK

#ifdef COMPARISON_OPERATORS
	Fraction A(1, 2);
	Fraction B(5, 10);
	cout << (A == B) << endl;
	cout << (A != B) << endl;
	cout << (A > B) << endl;
	cout << (A >= B) << endl;
#endif // COMPARISON_OPERATORS

#ifdef COUT_CHECK
	Fraction A;
	cout << A << endl;
	Fraction B(5);
	cout << B << endl;
	Fraction C(1, 2);
	cout << C << endl;
	Fraction D(2, 3, 4);
	cout << D << endl;
#endif // INPUT_OUTPUT 
	
#ifdef INPUT_CHECK
	Fraction A;
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << "Вы ввели: " << A << endl;
#endif // INPUT_CHECK


}




/*							ПРЕОБРАЗОВАНИЕ ТИПОВ
В языке С++ существуют явные и неявные преобразования типов. 
Явные преобразования выполняет программист, а неявные - компилятор.
Для того чтобы явно преобразовать значение в другой тип данных необходимо написать желаемый тип данных в круглых скобках перед значением.
(type)value; - C-like notation;      //type(value); - Functional 
Как явные так и неявные преобразования бывают от меньшего к большему и от большего к меньшему. При чем второе может привести к потере данных.
Все операторы С++ неявно приводят меньшее значение к большему типу в ввыражении, кроме присваиваний.
Операторы присваивания всегда приводят значение справа к типу слева. Независимо от того в какую сторону идет преобразование.
В ООП можно преобразовывать значения из других типов в наш тип, или же из нашего типа в другие типы.
За преобразования друних типов в наш отвечает конструктор с одним параметром и оператор присваивания.
При чем втрой без первого не работает. 
Для преобразования наших объектов в другие типы данных в классе должны быть соответсвующие операторы преобразования (type-cast operators)
Ключевое слово explicit перед конструктором с одним параметром запрещает неявные преобразования типов.
И если мы хотим что-то преобразовать в наш объект, то это можно сделать только явным образом.
							ПРЕОБРАЗОВАНИЕ НАШИХ ОБЪЕКТОВ В ДРУГИЕ ТИПЫ
Для того чтобы наши объекты приводить к другим типам данных в классе должны быть соответсвующие операторы преобразования. 
Операторы преобразования - это обычные методы, имя которых состоит из ключевого слова оператор и спецификатора существующего типа.
	operator type()
	{
	.....
	}
	У операторов преобразования не пишут тип возвращемого значения, поскольку он и так понятен по имени оператора.
	Операторы преобразования в обзязательном порядке возвращают значение. 
	Операторы преобразования можно перегружать только в классе
	К операторам преобразования также применимо ключевое слово explicit. Оно также запрещает неявные преобразования 



*/