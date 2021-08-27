#include <iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);


class String
{
	unsigned int size;		//Размер строки в байтах 
	char* str;				//Указатель на строку в динамической памяти 
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
	explicit String(unsigned int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};		//{}  обнуляют выделяемую память 
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str)  //константный указатель на char - это строковая константа
	{
		//while (str[size++]);
		this->size = strlen(str) + 1;	//+1 потому что this->size хранит размер в Байтах,
										//а strlen() считает размер в символах
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "1ArgConstructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "Copy constructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;  //[] показывают, что нужно удалить массив.
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
	//Оператор квадратные скобки возвращает значение по индексу 
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
	//1)	Создаем строку, в которую поместим результат:
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
	String str(5);			//explicit consrtuctor можно вызвать только так,
							//и нельзя вызвать оператором =
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