#include <iostream>
#include <cstddef>
using namespace std;

// ДАЛЬНЕЙШИЙ КОД, В ТОМ ЧИСЛЕ В СЛЕДУЮЩИХ ФАЙЛАХ, НЕ ФАКТ ЧТО ПРАВИЛЬНО РАБОТАЕТ

template <typename T>
class Array
{ 
private:
	T* myArray;
	size_t n;
public:
	explicit Array(size_t size = 0, const T& value = T())
	{
		myArray = new T[size];
		for (int i = 0; i < size; i++)
		{
			myArray[i] = value;
			cout << myArray[i] << endl;
		}
		n = size;
	}
	Array(const Array& mas, size_t size)
	{
		cout << "Копирование..." << endl;
		myArray = new T[size];
		for (int i = 0; i < size; i++)
		{
			myArray[i] = mas[i];
			cout << myArray[i] << endl;
		}
		n = size;
	}
	~Array()
	{
		delete[] myArray;
	}
	Array& operator=(const Array& mas)
	{
		cout << "Присваивание..." << endl;
		for (int i = 0; i < n; i++)
		{
			myArray[i] = mas[i];
			cout << myArray[i] << endl;
		}
		return *this;
	}
	T& operator[](size_t idx)
	{
		return myArray[idx];
	}
	const T& operator[](size_t idx) const
	{
		return *(myArray + idx);
	}
	size_t size() const { return n; }
};


class Student
{
public:
	string name;
	int number;
	Student() {};

	Student(string name, int number) : name{ name }, number{ number }
	{
		cout << name << "  " << number << endl;
	}
};

ostream& operator << (std::ostream& os, const Student& person)
{
	return os << person.name << " " << person.number;
}

int main2()
{
	setlocale(LC_ALL, "RUS");
	Student ann("Ann", 1);
	Student john("John", 2);
	Array<Student> arr (3, ann);
	Array<Student> arr1(3, john);
	return 0;
}