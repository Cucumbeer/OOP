#include <iostream>
using namespace std;

class String
{
	unsigned int size;		//������ ������ � ������ 
	char* str;				//��������� �� ������ � ������������ ������ 
public:
	String(unsigned int size = 80)
	{
		this->size = size;
		this->str = new char[size];
		cout << "DefConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;  //[] ����������, ��� ����� ������� ������.
		cout << "Destructor:\t" << this << endl;
	}

	//			Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	String str;
	str.print();
}