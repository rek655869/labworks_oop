#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main11()
{
	setlocale(LC_ALL, "RUS");
	ifstream file("old.txt");
	string s;
	while (getline(file, s))
	{
		s = regex_replace(s, regex(R"(1)"), "один");
		s = regex_replace(s, regex(R"(0)"), "ноль");
		cout << s << endl;
	}
	return 0;
}