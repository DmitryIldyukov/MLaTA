#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//	Выполнил Ильдюков Дмитрий ПС-22
// 
//	7.3. Видеоконференция (5)
//		Несколько бизнесменов собираются обсудить общие проблемы на видеоконференции.Каждый из них имеет в своем календаре отрезки свободного времени.
//	Для обеспечения кворума конференция должна проходить в такой период, когда в любой момент времени на ней могут присутствовать достаточное количество бизнесменов.
//	При этом состав участников может изменяться.Требуется найти максимальный по продолжительности отрезок времени для видеоконференции.
//	Если ответов несколько, то предпочтительнее наиболее раннее время для этого мероприятия.
//		Ввод.В первой строке входного файла INPUT.TXT содержатся через пробел целые числа N и M – общее количество бизнесменов и минимально необходимое количество для кворума(2 ≤ M ≤ N ≤ 10).
//	В каждом из следующих N блоков задана информация об отрезках свободного времени бизнесменов.В первой строке блока указано количество отрезков Ni.
//	Каждая из следующих Ni строк описывает очередной отрезок свободного времени в виде двух целых чисел A и B через пробел, где A – начало отрезка, а B его конец(0 ≤ A < B ≤ 109).
//	Отрезки свободного времени каждого бизнесмена не должны пересекаться между собой даже своими границами.Общее количество отрезков по всем бизнесменам не должно превышать 2×105.
//		Вывод.В первой строке выходного файла OUTPUT.TXT выдается максимальная длина такого отрезка, в каждой точке которого свободно не менее M бизнесменов.
//	Во второй строке указываются границы этого отрезка.Если отрезка ненулевой длины не находится, то вывод должен состоять из единственной строки со значением 0.
// 
//	Примеры
//		Ввод 1     Ввод 2     Ввод 3
//		3 2        3 2        3 2
//		2          1          1
//		20 40      5 10       0 20
//		1 7        1          1
//		1          12 15      1 8
//		3 24       2          1
//		1          20 40      6 18
//		12 15      0 5        Вывод 3
//		Вывод 1    Вывод 2    17
//		4          0          1 18
//		3 7
//
//	Среда раздаботки: Visual Studio 2019

struct Point {
	long long coordinate;
	int vid;
	long long id;
};

bool Initialization(int N, std::vector<Point>& freeTimeSlots, std::ifstream& input)
{
	int freeTimeSlotsCount;
	for (long long i = 1; i <= N; i++)
	{
		input >> freeTimeSlotsCount;
		for (long long j = 0; j < freeTimeSlotsCount; j++)
		{
			long long first, second;
			input >> first >> second;
			if (first > second || second > 1000000000)
				return false;
			Point firstPoint;
			firstPoint.coordinate = first;
			firstPoint.id = i;
			firstPoint.vid = 1;
			freeTimeSlots.push_back(firstPoint);
			Point secondPoint;
			secondPoint.coordinate = second;
			secondPoint.id = i;
			secondPoint.vid = -1;
			freeTimeSlots.push_back(secondPoint);
		}
	}

	input.close();

	return true;
}

bool isCorrectInput(int N, int M)
{
	if (M < 2 || M > N || N > 10 || N < 2)
	{
		std::cout << "Invalid input\n";
		return false;
	}
	return true;
}

void Sort(std::vector<Point>& vec)
{
	std::sort(vec.begin(), vec.end(), [](const Point first, const Point second) {
		return first.coordinate < second.coordinate;
	});
}

std::vector<std::pair<long long, long long>> GetAllTimesSlots(int M, std::vector<Point>& freeTimeSlots)
{
	long long workersAtTheTime = 0;
	std::vector<std::pair<long long, long long>> times;

	bool flag = false;
	long long first, second;

	for (int i = 0; i < freeTimeSlots.size(); i++)
	{
		workersAtTheTime += freeTimeSlots[i].vid;
		if (workersAtTheTime == M && !flag)
		{
			first = freeTimeSlots[i].coordinate;
			flag = true;
		}
		if (workersAtTheTime < M && flag)
		{
			second = freeTimeSlots[i].coordinate;
			std::pair<long long, long long> tempPair;
			tempPair.first = first;
			tempPair.second = second;
			times.push_back(tempPair);
			flag = false;
		}
	}

	return times;
}

void GetMaxTime(std::vector<std::pair<long long, long long>> times, long long& maxTime, long long& maxLeft, long long& maxRight)
{
	maxTime = 0;

	for (int i = 0; i < times.size(); i++)
	{
		long long time = times[i].second - times[i].first;
		if (time > maxTime)
		{
			maxTime = time;
			maxLeft = times[i].first;
			maxRight = times[i].second;
		}
	}
}

int main()
{
	std::ifstream input("input6.txt");
	if (!input)
	{
		std::cout << "File is not exist!\n";
		return 1;
	}

	int N, M;
	input >> N >> M;

	if (!isCorrectInput(N, M))
		return 1;
	std::vector<Point> freeTimeSlots;

	if (!Initialization(N, freeTimeSlots, input))
	{
		std::cout << "The second number must be greater than the first and less than 1000000000\n";
		return 1;
	}
	Sort(freeTimeSlots);
	std::vector<std::pair<long long, long long>> times = GetAllTimesSlots(M, freeTimeSlots);
	long long maxLeft = 0, maxRight = 0, maxTime = 0;
	GetMaxTime(times, maxTime, maxLeft, maxRight);
	std::ofstream output("output.txt");
	if (maxTime > 0)
		output << maxTime << '\n' << maxLeft << ' ' << maxRight << '\n';
	else
		output << '0' << '\n';

	output.close();

	return 0;
}