#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>




int const row = 5;
int const col = 4;
int arr[row][col];
int ask;
int count = 0;
int sum[row];
int nmin, bsum, barr;
void input()
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				printf("Введите элемент массива %d строки, %d cтолбца: ", i + 1, j + 1);
				scanf_s("%d\n", &arr[i][j]);
			}
		}
	}
void file_input()
{
	ifstream fin;
	fin.open("mass.txt");
	if (fin.is_open())
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				arr[i][j] = fin;
			}
		}
	}
	else
	{
		printf("Ошибка открытия файла");

	}
}


int first_task()
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (arr[j][i] == 0)
			{
				count += 1;
				break;

			}

		}
	}
	return(col - count);
}
int second_task()
{
	for (int i = 0; i < row; i++)
	{
		sum[i] = 0;
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] > 0 && arr[i][j] % 2 == 0)
			{
				sum[i] += arr[i][j];
			}


		}
	}

	
	for (int i = 0; i < row - 1; i++)
	{

		for (int j = i + 1; j < row; j++)
		{
			nmin = i;
			if (sum[j] < sum[nmin])
				nmin = j;
			bsum = sum[i];
			sum[i] = sum[nmin];

			sum[nmin] = bsum;
			for (int j = 0; j < col; j++)
			{
				barr = arr[i][j];
				arr[i][j] = arr[nmin][j];
				arr[nmin][j] = barr;
			}

		}
	}
}
void output()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
			if (j == (col - 1))
			{
				printf("| %d", sum[i]);
			}
		}
		printf("\n");
	}
}

int main()
	{
		SetConsoleOutputCP(1251);
		printf("Введите способ ввода данных:\n 1 - Ручной\n 2 - из файла\n");
		scanf_s("%d", &ask);
		if (ask == 1)
		{
			input();
		}
		if (ask == 2)
		{
			file_input();
		}

}
