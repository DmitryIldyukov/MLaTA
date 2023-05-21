#include <iostream>
#include <fstream>

//	Выполнил Ильдюков Дмитрий ПС-22
//
//  9.2.Простоватые числа(3)
//  Студент Вася отыскивает простые числа в диапазоне от 1 до N(1 ≤  N ≤ 1018).Если число M, не превосходящее N, не делится на  2, 3 и 5, 
//  Вася называет его “простоватым”.По заданному значению N найти количество простоватых чисел.
//  Ввод.В единственной строке файла INPUT.TXT находится число N.
//  Вывод.В единственную строку файла OUTPUT.TXT вывести количество простоватых чисел.
//  Пример
//  Ввод
//  10
//  Вывод
//  2
//
//	Среда раздаботки: Visual Studio 2019

int main()
{
    std::ifstream input("input.txt");
    if (!input)
    {
        std::cout << "File is not open!" << std::endl;
        return 1;
    }

    long long number;

    input >> number;
    input.close();

    if (number < 1 || number > 1000000000000000)
    {
        std::cout << "Invalid input!" << std::endl;
        return 1;
    }

    std::ofstream output("output.txt");
    output << number - number / 2 - number / 3 - number / 5 + number / 6 + number / 10 + number / 15 - number / 30 << std::endl;
    output.close();

    return 0;
}