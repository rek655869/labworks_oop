#include <iostream>
#include <string>
using namespace std;
 

class IncorrectNumber
{
public:
	char sym;
	IncorrectNumber(char sym): sym{ sym }{}
};

int to_int(char c)
{
	if ((int(c) < 48 || int(c) > 57))
		throw IncorrectNumber(c);
	else
		return stoi(&c);
}

int main() {
	setlocale(LC_ALL, "RUS");
	char sym;
	int res;
	cout << "Введите символ (только целое число):\n>";
	cin >> sym;
	try {
		res = to_int(sym);
	}
	catch (IncorrectNumber e) {
		cout << "Символ " << e.sym  << " это не целое число" << endl;
		return 0;
	}
	cout << "Вы ввели число " << res;
	return 0;
}