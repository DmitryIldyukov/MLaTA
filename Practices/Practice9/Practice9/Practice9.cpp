#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct Point {
	int x, y;
	bool infected;
};

std::vector<Point> FieldInitialization(int N)
{
	std::vector<Point> vec;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			Point temp;
			temp.x = i;
			temp.y = j;
			temp.infected = false;
			vec.push_back(temp);
		}

	return vec;
}

std::vector<Point> Infection(std::vector<Point> vec, Point point)
{
	int first = point.x;
	int second = point.y;
	for (int i = 0; i < vec.size(); i++)
	{
		if ((vec[i].x == point.x && vec[i].y == point.y - 1) ||
			(vec[i].x == point.x && vec[i].y == point.y + 1) ||
			(vec[i].x == point.x - 1 && vec[i].y == point.y) ||
			(vec[i].x == point.x + 1 && vec[i].y == point.y)
			)
			vec[i].infected = true;
	}

	return vec;
}

int main()
{
	std::ifstream input("input.txt");
	if (!input)
	{
		std::cout << "File is not exist!\n";
		return 1;
	}
	std::string coordinates;
	int N, M, first, second;
	input >> N;
	input >> M;
	std::vector<Point> pointVector = FieldInitialization(N);

	for (int i = 0; i < M; i++)
	{
		input >> first;
		input >> second;
		for (auto& point : pointVector)
			if (point.x == first - 1 && point.y == second - 1)
				point.infected = true;
	}

	bool allPointsInfected = false;
	int counter = 1;
	std::vector<Point> tempVector;
	tempVector = pointVector;

	while (!allPointsInfected)
	{
		allPointsInfected = true;
		for (int i = 0; i < pointVector.size(); i++) {
			if (pointVector[i].infected == true)
				tempVector = Infection(pointVector, pointVector[i]);
		}
		pointVector = tempVector;
		counter++;
		for (const auto& point : pointVector)
			if (point.infected == false)
			{
				allPointsInfected = false;
				break;
			}
	}

	std::cout << counter;

	system("pause");
	return 0;
}