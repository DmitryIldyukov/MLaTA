﻿#include <iostream>
#include <fstream>
#include <vector>

// Выполнил Ильдюков Дмитрий ПС-22
//
//  5.4.Возрастающая таблица(4)
//  Таблица обладает следующими свойствами :
//  в заголовках строк записаны числа, начиная с 1, каждое следующее на 2 единицы больше
//  предыдущего;
//  в заголовках столбцов записаны числа, начиная с 1, каждое следующее в 2 раза больше
//  предыдущего;
//  в ячейке таблицы на пересечении i - й строки и j - го столбца записано произведение
//  заголовков i - й строки и j - го столбца.
//  Требуется написать программу, которая по значению ячейки таблицы определит числа в заголовках строки и столбца.
//  Ввод.Первая строка содержит натуральное число T(1 ≤ T ≤ 105) — количество наборов входных данных.В каждой из следующих T строк задаётся натуральное число X(1 ≤ X ≤ 109) — значение ячейки таблицы.
//  Вывод.Для каждой из T строк выведите два натуральных числа, разделённых пробелом — заголовки строки и столбца, на пересечении которых находится ячейка со значением X.Гарантируется, что для любых входных данных эти значения определяются однозначно.
//  Пример
//  Ввод
//  3
//  80
//  16
//  576
//  Вывод
//  5 16
//  1 16
//  9 6
//
//  Среда разработки: Visual Studio 2019

int main()
{
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");

	if (!input)
	{
		std::cout << "File is not exist\n";
		return 1;
	}

	std::vector<long long> Vec;
	long long twoInStepen = 1;
	while (twoInStepen < 100000000)
	{
		Vec.push_back(twoInStepen);
		twoInStepen *= 2;
	}

	long long number, counter;
	input >> counter;

	if (counter < 1 || counter > 100000)
	{
		std::cout << "Invalid input\n";
		return 1;
	}

	for (int i = 0; i < counter; i++)
	{
		input >> number;

		if (number < 1 || number > 1000000000)
		{
			std::cout << "Invalid input\n";
			return 1;
		}

		if (number % 2 != 0)
			output << number << " 1\n";
		else
			for (int i = Vec.size() - 1; i >= 0; i--)
				if (number % Vec[i] == 0)
				{
					output << number / Vec[i] << ' ' << Vec[i] << '\n';
					break;
				}
	}
	return 0;
}
