#include <iostream>

using namespace std;

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
		}
		n = size;
	}
	~Array()
	{
		delete[] myArray;
	}
	const T& operator[](int idx) const
	{
		return myArray[idx];
	}
	size_t size() const { return n; }
};


template <typename T>
void flatten(const Array<T>& array, ostream& out)
{
	for (int i = 0; i < array.size(); i++) {
		out << array[i] << " ";
	}
}

template <typename T>
void flatten(const Array< Array<T> >& array, ostream& out)
{
	for (int i = 0; i < array.size(); i++) {
		flatten(array[i], out);
	}
}

int main26() {
	Array<int> arr(2, 0);
	flatten(arr, cout); 
	Array< Array<int> > arr2(4, arr);
	flatten(arr2, cout);

	return 0;
}