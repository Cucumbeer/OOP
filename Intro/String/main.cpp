#include <iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);


class String
{
	unsigned int size;		//–азмер строки в байтах 
	char* str;				//”казатель на строку в динамической пам€ти 
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
		//this->str = new char[size] {};		//{}  обнул€ют выдел€емую пам€ть 
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str):String(strlen(str)+1)  //ћы делегируем выделение пам€ти первому конструктору.
	{
		//while (str[size++]);
		//this->size = strlen(str) + 1;	//+1 потому что this->size хранит размер в Ѕайтах,
										//а strlen() считает размер в символах
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
	//ќператор квадратные скобки возвращает значение по индексу 
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
	//1)	—оздаем строку, в которую поместим результат:
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
							//и нельз€ вызвать оператором =
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
	Ќаследование(Inheritance) - Ёто способность классов наследовать свойства других классов. 
	ѕод свойствами в данном случае понимаютс€ переменные и методы. 
	Ќаследование позвол€ет одному классу использовать код другого класса, что приводит к повторному использованию кода и следовательно сокращает объем исходного кода.
	ѕри наследовании различают базовый класс(–одительский класс) и производный класс(ƒочерний)
	Ѕазовый класс не знает сколько и каких классов от него унаследовано. ј дочерний класс знает только своего родител€.
	Ќаследование позвол€ет обобщить свойства разных классов и вынести их в отдельный класс. Ёто в значительной степени сокращает объем кода 
	ќбобщение еще называют Generalisation.
	ƒочерние классы дополн€ют свойства базового класса своими собственными свойствами. 
	Ќаследование отображает отношени€ между классами типа: "явл€етс€".
	» поэтому прежде, чем что-то от чего-то наследовать нужно убедитьс€ в том, что что-то €вл€етс€ чем-то.
	Ќапример: кот €вл€етс€ животным.
	»нициализаци€ в заголовке возможна только в конструкторах.
*/