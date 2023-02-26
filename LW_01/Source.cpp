#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func1(double a, double b); // функция для задания 1
double factorial(double i); // вычисление факториала числа
double func2(double x, int n); // функция (вычисление n-го члена) для задания 2
double decomp(double x, double eps); // разложение функции в ряд для задания 2

int main1()
{
	setlocale(LC_ALL, "RUS");

	int choice = -1;  // выбранный пункт меню
	double a, b, res;
	const double eps = 0.001; // значение точности для задания 2
	double x1 = -2.2, x2 = 0.75, x3 = 5.6; // значения x для задания 2

	while (choice != 0)
	{
		cout << "Выберите задание:" << endl
			<< "  1. Найти значение алгебраического выражения" << endl
			<< "  2. Составить программу вычисления функции F(x), разложенной в ряд" << endl
			<< "  4. Написать программу определения знака введенного числа" << endl
			<< "  0. Выйти из программы" << endl
			<< ">";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "           17,8 * a + cos^2(13,2 * b^2 + 2,4 * b + 3,7)" << endl
				<< "           --------------------------------------------" << endl
				<< "F(a, b) =          /     13,7 - sin(a^2 + b)" << endl
				<< "              \\   /  e + ----------------------" << endl
				<< "               \\ /      -17,478 * a + 13,2 * b" << endl << endl
				<< "Введите значения a и b:" << endl
				<< ">";
			cin >> a >> b;
			res = func1(a, b);
			cout << "Результат: " << res << endl;
			break;
		}
		case 2:
		{
			cout << "           x^3   x^5                  x^2n-1" << endl
				<< "F(x) = x - --- + --- - ... + (-1)^n-1 ------- + ..." << endl
				<< "            3!    5!                  (2n-1)!" << endl << endl;

			cout << setw(5) << "x" << setw(13) << "f(x)" << endl
				<< setw(5) << x1 << setw(13) << decomp(x1, eps) << endl
				<< setw(5) << x2 << setw(13) << decomp(x2, eps) << endl
				<< setw(5) << x3 << setw(13) << decomp(x3, eps) << endl;
			break;
		}
		case 4:
		{
			cout << "Введите любое число:" << endl
				<< ">";
			cin >> a;
			if (a > 0)
				cout << "Число положительное" << endl;
			else if (a < 0)
				cout << "Число отрицательное" << endl;
			else
				cout << "Число является нулем" << endl;
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


double func1(double a, double b)
{
	double chisl = 17.8 * a + pow(cos(13.2 * pow(b, 2) + 2.4 * b + 3.7), 2);
	double znam = sqrt(exp(1) + (13.7 - sin(pow(a, 2) + b)) / (-17.478 * a + 13.2 * b));
	double result = chisl / znam;
	return result;
}

double factorial(double i)
{
	if (i == 0)
		return 1;
	else
		return i * factorial(i - 1);
}

double func2(double x, int n)
{
	double res1 = pow(-1, n - 1);
	double res2 = pow(x, 2 * n - 1);
	double res3 = factorial(2 * n - 1);
	double result = res1 * (res2 / res3);
	return result;
}

double decomp(double x, double eps)
{
	double temp = func2(x, 1);  // первый член ряда
	double temp2 = temp + func2(x, 2);  // второй член ряда
	int n = 3;  // порядковый номер члена ряда
	while (abs(temp2 - temp) > eps)
	{
		temp = temp2;
		temp2 = temp + func2(x, n);
		n++;
	}
	return temp2;
}