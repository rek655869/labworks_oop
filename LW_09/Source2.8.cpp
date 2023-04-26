#include <iostream>
using namespace std;

template <typename T, typename V>
struct SameType
{
	static const bool value = false;
};

template <typename W>
struct SameType<W, W>
{
	static const bool value = true;
};

int main28()
{
	SameType<int, int> s1;
	cout << s1.value << endl;
	SameType<int, double> s2;
	cout << s2.value;
	return 0;
}