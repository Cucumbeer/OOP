#include <iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);


class String
{
	unsigned int size;		//������ ������ � ������ 
	char* str;				//��������� �� ������ � ������������ ������ 
public:
	unsigned int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	 char* get_str()
	{
		return str;
	}
	explicit String(unsigned int size = 80):size(size), str(new char[size]{})
	{
		//this->size = size;
		//this->str = new char[size] {};		//{}  �������� ���������� ������ 
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str):String(strlen(str)+1)  //�� ���������� ��������� ������ ������� ������������.
	{
		//while (str[size++]);
		//this->size = strlen(str) + 1;	//+1 ������ ��� this->size ������ ������ � ������,
										//� strlen() ������� ������ � ��������
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "1ArgConstructor:\t" << this << endl;
	}
	String(const String& other): String(other.str)
	{
		//this->size = other.size;
		//this->str = new char[size] {};
		//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "Copy constructor:" << this << endl;
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

	//			Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "Copy assignment: " << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	//�������� ���������� ������ ���������� �������� �� ������� 
	const char& operator[](unsigned int i)const  //i - index
	{
		return str[i];
	}
	 char& operator[](unsigned int i)  //i - index
	{
		return str[i];
	}
	
};
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	//1)	������� ������, � ������� �������� ���������:
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHECK
	//String str = 5;		//Conversion from int to String
	String str(5);			//explicit consrtuctor ����� ������� ������ ���,
							//� ������ ������� ���������� =
	str.print();
	String str1 = "Hello";
	str1 = str1;
	str1.print();

	String str2 = str1;
	str2.print();

	String str3;
	str3 = str2;
	str3.print();
#endif // CONSTRUCTORS_CHECK

	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;

	/*String str3 = str1 + " " + str2;
	cout << str3 << endl;*/
 	cout << str1 + str2 << endl;
	str1 += str2;
	cout << str1 << endl;
}


/*
	������������(Inheritance) - ��� ����������� ������� ����������� �������� ������ �������. 
	��� ���������� � ������ ������ ���������� ���������� � ������. 
	������������ ��������� ������ ������ ������������ ��� ������� ������, ��� �������� � ���������� ������������� ���� � ������������� ��������� ����� ��������� ����.
	��� ������������ ��������� ������� �����(������������ �����) � ����������� �����(��������)
	������� ����� �� ����� ������� � ����� ������� �� ���� ������������. � �������� ����� ����� ������ ������ ��������.
	������������ ��������� �������� �������� ������ ������� � ������� �� � ��������� �����. ��� � ������������ ������� ��������� ����� ���� 
	��������� ��� �������� Generalisation.
	�������� ������ ��������� �������� �������� ������ ������ ������������ ����������. 
	������������ ���������� ��������� ����� �������� ����: "��������".
	� ������� ������, ��� ���-�� �� ����-�� ����������� ����� ��������� � ���, ��� ���-�� �������� ���-��.
	��������: ��� �������� ��������.
	������������� � ��������� �������� ������ � �������������.
*/