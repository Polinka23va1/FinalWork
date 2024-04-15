#include <iostream>
#include <Windows.h>
int F(const int* arr, int n)
{
	if (n == 1) return arr[0];
	return arr[n - 1] * F(arr, n - 1);
}


int main()
{
	SetConsoleOutputCP(1251);
	int const N = 3;
	int product = 1;
	int arr[N];
	for (int i = 0; i < N; i++)
	{
		printf("Введите %d-й элемент массива:\n", i+1);
		scanf_s("%d", &arr[i]);
	}
	printf("Сумма элементов массива: %d", F(arr, N));
	printf("Хуй");
}