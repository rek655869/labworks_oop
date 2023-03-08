#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

class ARR
{
private:
	int n; // строка
	int m; // столбец
	int** Array;
public:
	ARR(int valueN, int valueM) // конструктор, позволяющий создать массив размерности n*m
	{
		n = valueN;
		m = valueM;
		Array = new int* [n];
		for (int i = 0; i < n; i++)
			Array[i] = new int[m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				Array[i][j] = rand() % 100 - 50;
		}
	}
	ARR(int** arr, int a, int b)  // конструктор для создания объекта из двумерного массива
	{
		n = a;
		m = b;
		Array = new int* [n];
		for (int i = 0; i < n; i++)
			Array[i] = new int[m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				Array[i][j] = arr[i][j];
		}
	}
	void SetNM(int valN, int valM)
	{
		n = valN;
		m = valM;
	}
	void Input() //ввод пользователем массива
	{
		Array = new int* [n];//выделение памяти под строки
		for (int i = 0; i < n; i++)
		{
			Array[i] = new int[n];
			for (int j = 0; j < m; j++)
				cin >> Array[i][j];
		}
	}
	void Output() //вывод массива
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << Array[i][j] << " ";
			}
			cout << endl;
		}
	}
	int Summ(int l) //сумма i-го столбца
	{
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (j == l) s += Array[i][j];
			}
		}
		return s;
	}
	int GetNulls() //кол-во нулевых элементов
	{
		int b = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Array[i][j] == 0) b++;
			}
		}
		return b;
	}
	void Scal(int s) // эл-ты главной диагонали = скляру
	{
		for (int i = 0; i < n; i++)
			Array[i][i] = s;
	}
	void DelMass()
	{
		delete[]Array;
	}

	int* operator[](int elem)  // двумерная индексация
	{
		return Array[elem];
	}

	ARR& operator++ ()  // префиксный инкремент
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				Array[i][j] += 1;
		return *this;
	}

	ARR& operator-- ()  // префиксный декремент
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				Array[i][j] -= 1;
		return *this;
	}

	operator bool() const  // true false
	{
		return n == m;
	}

	ARR operator+ (ARR arr)  // бинарный +
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				Array[i][j] += arr[i][j];
		return *this;
	}

	int** to_arr()
	{
		return Array;
	}
};



int main()
{
	setlocale(LC_ALL, "RUS");
	int vibor;
	int n, m, skal, sumcol, k;
	char v;
	cout << "Введите то, что хотите, чтобы сделала программа\n";
	cout << "1.Ввести элементы массива с клавиатуры\n";
	cout << "2.Вывести элементы массива на экран\n";
	cout << "3.Вычислить сумму элементов i-го столбца\n";
	cout << "4.Вычислить количество нулевых элементов\n";
	cout << "5.Установить значение всех элементов главной диагонали массива, равное скаляру\n";
	cout << "6.Обратиться к определённому элементу массива\n";
	cout << "7.Увеличить/уменьшить все значения на 1\n";
	cout << "8.Определить, является ли массив квадратным\n";
	cout << "9.Сложить два массива\n";
	cout << "10.Преобразовать массив в класс\n";
	cout << "0.Завершение программы\n";
	cout << ">";
	cin >> vibor;
	while (vibor < 0 || vibor > 10)
	{
		cout << "Неверно, попробуйте ещё раз\n";
		cout << "Введите то, что хотите, чтобы сделала программа\n";
		cout << ">";
		cin >> vibor;
	}

	cout << "Введите размер массива\n>";
	cin >> n;
	cout << ">";
	cin >> m;
	ARR massiv(n, m);
	ARR extra_massiv(n, m);
	massiv.SetNM(n, m);
	while (vibor != 0)
	{

		if (vibor == 1)
		{

			cout << "Введите массив вручную\n>";
			massiv.Input();
		}
		if (vibor == 2)
		{
			cout << "Вывод  массива\n";
			massiv.Output();
		}
		if (vibor == 3)
		{
			cout << "Введите номер столбца\n>";
			cin >> sumcol;
			cout << "Сумма = ";
			int c = massiv.Summ(sumcol - 1);
			cout << c << " " << endl;
		}
		if (vibor == 4)
		{
			cout << "Количество нулевых элементов = ";
			k = massiv.GetNulls();
			cout << k << " " << endl;
		}
		if (vibor == 5)
		{
			cout << "Введите скаляр\n>";
			cin >> skal;
			massiv.Scal(skal);
		}
		if (vibor == 6)
		{
			cout << "Введите строку и столбец\n";
			cin >> n >> m;
			cout << massiv[n - 1][m - 1] << endl;
		}
		if (vibor == 7)
		{
			cout << "Если вы хотите увеличить значения, введите +, иначе -\n";
			cin >> v;
			if (v == '+')
				++massiv;
			else
				--massiv;
		}
		if (vibor == 8)
		{
			if (massiv)
				cout << "Массив квадратный\n";
			else
				cout << "Массив не квадратный\n";
		}
		if (vibor == 9)
		{
			extra_massiv.Output();
			cout << "Прибавим к исходному массиву\nРезультат:\n";
			massiv + extra_massiv;
			massiv.Output();
		}
		if (vibor == 10)
		{
			int** p_arr;
			p_arr = new int* [3];
			for (int i = 0; i < 3; i++)
				p_arr[i] = new int[2];
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 2; j++)
					p_arr[i][j] = rand() % 100 - 50;
			}
			ARR massiv1(p_arr, 3, 2);
			massiv1.Output();
			massiv = massiv1;
		}
		cout << "Введите то, что хотите, чтобы сделала программа\n";
		cin >> vibor;
	}
	if (vibor == 0)
	{
		cout << "Завершение работы с программой\n";
		massiv.DelMass();
		return 0;
	}

	return 0;
}

