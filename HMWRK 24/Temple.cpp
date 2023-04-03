#include <iostream>
#include <cstdlib>
#include <ctime>

// Кодировка UTF-8

void fill_arr(int arr[], int size, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (max - min) + min;
}
void show_arr(int arr[], const int l) {
	std::cout << "[";
	for (int i{}; i < l; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
	std::cout << std::endl;
}
void resize_arr(int*& arr, int l, int num) {
	if (num <= 0)
		return;
	int* tmp = new int[l + num] {};
	for (int i{}; i < l; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");

	int n,m,new_s;

	std::cout << "Задача 1.\nВведите длины массивов ->";
	std::cin >> n >> m;

	int* A = new int[n] {};
	int* B = new int[m] {};
	fill_arr(A, n, -10, 10);
	fill_arr(B, m, 15, 50);
	std::cout << "Первый массив:\n";
	show_arr(A, n);
	std::cout << "Второй массив:\n";
	show_arr(B, m);
	int old_s = m + n;
	
	int* C = new int[n + m];
	for (int i{}; i < n; i++)
		C[i] = A[i];
	for (int i = n; i < old_s; i++)
		C[i] = B[i - n];

	std::cout << "Массив С:\n";
	show_arr(C, old_s);
	delete[] A;
	delete[] B;

	std::cout << "Задача 2.\nВведите новый размер массива -> ";
	std::cin >> new_s;
	resize_arr(C, old_s,new_s);
	show_arr(C, new_s);



	return 0;
}