#include <iostream>
#include <string>
using namespace std;
 

class IncorrectNumber
{
private:
	string msg;
public:
	IncorrectNumber(string msg): msg{msg}{}

	string get_message() { return msg; }
};

int to_int(char c)
{
	if ((int(c) >= 32 && int(c) <= 47) || (int(c) >= 58 && int(c) <= 64) || (int(c) >= 91 && int(c) <= 96) || (int(c) >= 123 && int(c) <= 127))
		throw IncorrectNumber("Ввод специальных символов запрещён");
	else if ((int(c) >= 65 && int(c) <= 90) || (int(c) >= 97 && int(c) <= 122))
		throw IncorrectNumber("Ввод букв запрещён");
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
		cout << e.get_message() << endl;
		return 0;
	}
	cout << "Вы ввели число " << res;
	return 0;
}