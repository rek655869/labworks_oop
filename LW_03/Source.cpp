#include <iostream>
#include <cmath>
using namespace std;

int** fill_matrix(int**, int);  // заполнение квадратной матрицы
void print_matrix(int**, int);  // вывод квадратной матрицы
int det(int**, int); // вычисление определителя
int** transp_matrix(int**, int);  // транспонирование
int** reverse_matrix(int**, int**, int, int);  // вывод обратной матрицы
int** mult_matrix(int**, int**, int**, int); // умножение матриц


int main()
{
	setlocale(LC_ALL, "RUS");
	const int n = 5;
	int** arr = NULL, **trasp_arr = NULL, **new_arr = NULL, **rev_arr = NULL;

	cout << "Исходная матрица:" << endl;
	arr = fill_matrix(arr, n);
	print_matrix(arr, n);

	int d = det(arr, n);
	cout << "Определитель: " << d << endl << endl;

	cout << "Транспонированная матрица:" << endl;
	trasp_arr = transp_matrix(arr, n);
	print_matrix(trasp_arr, n);
	cout << endl;

	cout << "Матрица дополнений:" << endl;
	rev_arr = reverse_matrix(trasp_arr, rev_arr, n, d);
	print_matrix(rev_arr, n);
	cout << endl;

	cout << "Обратная матрица:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%10.3g", arr[i][j] / (float)d);
		cout << endl;
	};
	cout << endl;

	cout << "Результат умножения:" << endl;
	new_arr = mult_matrix(arr, rev_arr, new_arr, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%10g", new_arr[i][j] / (float)d);
		cout << endl;
	}

	delete[] arr;
	delete[] trasp_arr;
	delete[] rev_arr;
	delete[] new_arr;
	return 0;
}



void print_matrix(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%10d", arr[i][j]);
		cout << endl;
	}
}

int** fill_matrix(int** arr, int n)
{
	arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	int curr_str = 0, curr_col = 0, last_str = n - 1, last_col = n;
	int value = n * n;

	while (value)
	{
		last_col--;
		for (int i = last_col; i >= curr_col; i--, value--)  // идём по нижней строке
			arr[last_str][i] = value;

		last_str--;
		for (int i = last_str; i >= curr_str; i--, value--) // идём по левому столбцу
			arr[i][curr_col] = value;

		curr_col++;
		for (int i = curr_col; i <= last_col; i++, value--) // идём по верхней строке
			arr[curr_str][i] = value;

		curr_str++;
		for (int i = curr_str; i <= last_str; i++, value--) // идём по правому столбцу 
			arr[i][last_col] = value;
	}
	return arr;
}

int det(int** arr, int n)
{
	int d = 0;
	int k;
	int** next_arr = NULL; // матрица с зачеркнутой строкой и столбцом
	switch (n)
	{
	case 1:
		return arr[0][0];
	case 2:
		return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
	default:
		for (int i = 0; i < n; i++)  // разложение по первому столбцу
		{
			k = 0;
			next_arr = new int* [n - 1];  // создаем новую матрицу
			for (int j = 0; j < n; j++)
				if (i != j)
					next_arr[k++] = arr[j] + 1;
			d += pow(-1, i + 2) * arr[i][0] * det(next_arr, n - 1);
		};
		delete[] next_arr;
		return d;
	};
};

int** transp_matrix(int** arr, int n)
{
	int** trans = new int* [n];  // создаём матрицу, которая станет транспонированной
	for (int i = 0; i < n; i++)
		trans[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			trans[j][i] = arr[i][j];
	return trans;
}

int** reverse_matrix(int** trasp_arr, int** rev_arr,int n, int d)
{
	int add, k, new_d;
	int** next_arr;
	rev_arr = new int* [n];  // создаём матрицу
	for (int i = 0; i < n; i++)
		rev_arr[i] = new int[n];

	for (int i = 0; i < n; i++)  // вычисляем алгебр. дополнения и сразу заполняем матрицу
		for (int j = 0; j < n; j++)
		{
			int** next_arr = new int* [n - 1]; 
			for (int k = 0; k < n - 1; k++)
				next_arr[k] = new int[n - 1];

			int a = 0, b = 0;
			for (int y = 0; y < n; y++)
			{
				if (y != i)
				{
					for (int v = 0; v < n; v++)
					{
						if (v != j)
						{
							next_arr[a][b] = trasp_arr[y][v];
							b++;
						}
					}
					a++;
					b = 0;
				}
			}
			add = pow(-1, i + j + 2) * det(next_arr, n - 1);
			rev_arr[i][j] = add;
			delete[] next_arr;
		}
	return rev_arr;
}

int** mult_matrix(int** arr, int** rev_arr, int** new_arr, int n)
{
	new_arr = new int* [n];
	for (int i = 0; i < n; i++)
		new_arr[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			new_arr[i][j] = 0;
			for (int k = 0; k < n; k++)
				new_arr[i][j] += arr[i][k] * rev_arr[k][j];
		}
	return new_arr;
}