#include <iostream>
#include <string>
#include <fstream>
#define COUNT 8

using namespace std;
bool StringChisla(string& strr, int N);

typedef struct ZNAK {
	int TIME[2];
	int BDAY[3];
	string NAME;
	string ZODIAC;

} ZNAK;

int main()
{
	setlocale(LC_ALL, "RUS");

	int choice = -1;
	string strr;
	bool res = true;
	ZNAK BOOK[COUNT];
	bool flag = false;

	while (choice != 0)
	{
		cout << "Выберите задание:" << endl
			<< "  1. Выделить числа из строки" << endl
			<< "  2. Поменять местами самую длинную и самую короткую строки в файле" << endl
			<< "  3. Взаимодействие со структурой" << endl
			<< "  0. Выйти из программы" << endl
			<< ">";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
		{
			while (res)
			{
				cout << "Введите строку текста\n>";
				getline(cin, strr); //считывается всё
				int N = strr.length();
				res = StringChisla(strr, N);
				cout << endl;
			}
			break;
		}
		case 2:
		{
			ifstream file("text.txt"); 
			string str, min, max = "";

			getline(file, min);
			while (getline(file, str))
			{
				if (str.size() > max.size())
					max = str;
				if (str.size() < min.size())
					min = str;
			}
			cout << "Самая длинная строка:\n  " << max << endl
				<< "Самая короткая строка:\n  " << min << endl;

			file.clear();  
			file.seekg(0); // для того, чтбы пройтись по файлу заново
			ofstream output_file("new_next.txt");
			while (getline(file, str))
			{
				if (str == min)
					output_file << max;
				else if (str == max)
					output_file << min;
				else
					output_file << str;

				output_file << endl;
			}
			cout << "Результат выведен в файл new_text.txt" << endl;
			file.close();
			output_file.close();
			break;
			}
		case 3:
		{
			cout << "Заполните массив данными:" << endl;
			for (int i = 0; i < COUNT; i++)
			{
				cout << "Имя и фамилия:\n>";
				getline(cin, BOOK[i].NAME);

				cout << "Время рождения:\n>";
				cin >> BOOK[i].TIME[0] >> BOOK[i].TIME[1];

				cout << "Дата рождения:\n>";
				cin >> BOOK[i].BDAY[0] >> BOOK[i].BDAY[1] >> BOOK[i].BDAY[2];

				cout << "Знак Зодиака:\n>";
				cin >> BOOK[i].ZODIAC;
				cin.ignore();
				cout << endl;
			}
			cout << endl;

			cout << "Введите фамилию для поиска:\n>";
			cin >> strr;
			for (int i = 0; i < COUNT; i++)
			{
				if (BOOK[i].NAME.find(strr) != string::npos)
				{
					cout << "Имя и фамилия: " << BOOK[i].NAME << endl
						<< "Время рождения: " << BOOK[i].TIME[0] << ":" << BOOK[i].TIME[1] << endl
						<< "Дата рождения: " << BOOK[i].BDAY[0] << "." << BOOK[i].BDAY[1] << "." << BOOK[i].BDAY[2] << endl
						<< "Знак Зодиака: " << BOOK[i].ZODIAC << endl;
					flag = true;
					break;
				}
			}
			if (!flag)
				cout << "Человек с такой фамилией не найден" << endl;
			cout << endl;
			break;
		}
		case 0:
			exit(0);
		default:
		{
			cout << "Нет такого варианта" << endl;
			break;
		}
		}
		system("pause");
		system("cls");
	}
	return 0;
}



bool StringChisla(string& strr, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (strr[i] == '1' || strr[i] == '0' || strr[i] == '2' || strr[i] == '3' || strr[i] == '4' || strr[i] == '5' || strr[i] == '6' || strr[i] == '7' || strr[i] == '8' || strr[i] == '9')
			cout << strr[i];
	}
	if (strr[N - 4] == 'q' && strr[N - 3] == 'u' && strr[N - 2] == 'i' && strr[N - 1] == 't')
		return false;
	else
		return true;
}