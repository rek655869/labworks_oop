#include <iostream>
#include <cmath>
/*Дан двумерный массив размерностью 5 6, заполненный целыми числами с клавиатуры.
Сформировать одномерный массив, каждый элемент которого равен наибольшему по модулю
элементу соответствующего столбца.*/
#include <time.h>
#define MIN -1000
#define MAX 1000
using namespace std;

int* heap_sort(int* arr, int n); // пирамидальная сортировка

int main()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned int)time(NULL));
	int choice = -1;  // выбранный пункт меню
	int n;
	int x, sum = 0;
	int* arr;

	while (choice != 0)
	{
		cout << "Выберите задание:" << endl
			<< "  1. Одномерный массив из N целочисленных элементов" << endl
			<< "  2. Двумерный массив 5х6, заполненный целыми числами с клавиатуры" << endl
			<< "     Получить одномерный массив, где каждый элемент равен наибольшему по модулю элементу соответствующего столбца" << endl
			<< "  3. Пирамидальная сортировка" << endl
			<< "  0. Выйти из программы" << endl
			<< ">";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Введите количество элементов:\n>";
			cin >> n;
			arr = new int[n];

			cout << "1. Заполнение массива:" << endl;
			for (int i = 0; i < n; i++)
			{
				arr[i] = MIN + rand() % (MAX - MIN + 1);
				cout << "  A[" << i << "] = " << arr[i] << endl;

				// поиск макс. + элемента
				x = -1;
				if (arr[i] > 0 && arr[i] > x)
					x = arr[i];

				// сумма элементов
				sum += arr[i];
			}

			cout << "2. Максимальный положительный элемент = ";
			if (x != -1)
				cout << x << endl;
			else
				cout << "отсутствует" << endl;

			cout << "3. Сумма элементов массива = " << sum << endl;

			cout << "4. Ненулевые элементы в обратном порядке:" << endl;
			for (int i = n - 1; i >= 0; i--)
			{
				if (arr[i] > 0)
					cout << "  A[" << i << "] = " << arr[i] << endl;
			}
			delete[] arr;
			break;
		}
		case 2:
		{
			const int с = 5;
			const int m = 6;
			int A[с][m], B[m];
			cout << "Введите матрицу 5x6" << endl;
			for (int i = 0; i < с; i++)
				for (int j = 0; j < m; j++) // считываем матрицу
					cin >> A[i][j];
			for (int i = 0; i < m; i++)
			{
				B[i] = abs(A[0][i]);
				for (int j = 1; j < n; j++)
					if (abs(A[j][i]) > B[i]) // сравниваем со значением по модулю
						B[i] = A[j][i]; // присваиваем B[i] значение этого максимального элемента
			}
			cout << endl;
			for (int i = 0; i < m; i++)
				cout << B[i] << ' ';
			break;
		}
		case 3:
		{
			cout << "Введите количество элементов:\n>";
			cin >> n;
			arr = new int[n];
			cout << "Исходный массив:" << endl;
			for (int i = 0; i < n; i++)
			{
				arr[i] = MIN + rand() % (MAX - MIN + 1);
				cout << "  B[" << i << "] = " << arr[i] << endl;
			}
			arr = heap_sort(arr, n);
			cout << "Отсортированный массив:" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "  B[" << i << "] = " << arr[i] << endl;
			}
			delete[] arr;
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

int* heapify(int* arr, int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// Если левый дочерний элемент больше корня
	if (left < n && arr[left] > arr[largest])
		largest = left;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (right < n && arr[right] > arr[largest])
		largest = right;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		arr = heapify(arr, n, largest);
	}
	return arr;
}

// Основная функция, выполняющая пирамидальную сортировку
int* heap_sort(int* arr, int n)
{
	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		arr = heapify(arr, i, 0);
	}
	return arr;
}
