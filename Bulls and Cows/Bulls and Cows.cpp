#include "stdafx.h"
#include <iostream>
#include "math.h"
#include "locale.h"
#include "conio.h"

const int a = 1237;

int nCount(int n, int k) {
	return((n / (int)pow(10, k)) % 10);
}


int nBulls(int n, int a) {
	int sum = 0;
	for (int i = 0;i < 4;i++) {
		if (nCount(n, i) == nCount(a, i))
			sum++;
	}
	return sum;
}

int nCows(int n, int a) {
	int sum1 = 0;
	for (int i = 0;i < 4;i++) {
		for (int g = 0;g < 4;g++) {
			if (nCount(n, i) == nCount(a, g))
				sum1++;
		}
	}
	return sum1;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	std::cout << "Введите число: ";
	std::cin >> n;
	while (nBulls(n, a) != 4) {
		std::cout << "Быков: ";
		std::cout << nBulls(n, a);
		std::cout << "\n";
		std::cout << "Коров: ";
		std::cout << nCows(n, a);
		std::cout << "\n";
		std::cout << "Введите число: ";
		std::cin >> n;
	}
	std::cout << "VICTORY";
	_getch();
	return 1;
}