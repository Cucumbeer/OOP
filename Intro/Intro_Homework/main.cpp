#include <iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------------------------------------\n"
//#define CONSTRUCTORS OVERLOADING
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
#define ASSIGNMENT_CHECK


class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//Constructors:
	Point()
	{
		//Конструктор по умолчанию
		x = y = 0;
		cout << "constructor: \t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Single argument constructor: \t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: \t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy constructor: \t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor: \t" << this << endl;
	}
	
	//Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy assignment:\t\t" << this << endl;
		return *this;
	}
	
	//Methods:
	double distanse(const Point& other)
	{
		//B - this     A - other;
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void Print()
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}

};

void main()
{
	setlocale(LC_ALL, "");


#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(3);
	A.set_y(4);
	cout << A.get_x() << tab << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(9);
	cout << B.get_x() << tab << B.get_y() << endl;
	cout << delimiter << endl;
	cout << B.distanse(A);
	cout << delimiter << endl;
	cout << A.distanse(B) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A;    //Default constructor
	A.Print();
	Point B = 3;  //Single argument constructor
	B.Print();
	Point C(2, 3);  //Parametrised constructor
	C.Print();
	Point D = C;   //Copy constructor
	D.Print();
	Point E;
	E = C;		//Copy assignment
	E.Print();

#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(4, 5);
	cout << delimiter << endl;
	A.Print();
	B.Print();
	C.Print();
#endif // ASSIGNMENT_CHECK



}