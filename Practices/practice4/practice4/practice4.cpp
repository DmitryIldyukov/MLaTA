#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Point {
	double x, y;
};

void addToMas(std::vector<Point>& vec, double i, double j) {
	Point temp;
	temp.x = i + 1;
	temp.y = j + 1;
	vec.emplace_back(temp);
}

int main() {

	std::string fileName;
	std::cout << "Enter the name of the input file: ";
	std::cin >> fileName;
	std::ifstream inputFile(fileName);

	if (inputFile.is_open()) 
	{
		int M;
		int N;
		inputFile >> M;
		inputFile >> N;

		std::vector<std::vector<double>> Field(M, std::vector<double>(N));
		std::vector<Point> put;

		for (int i = 0; i < M; i++) 
		{
			for (int j = 0; j < N; j++)
			{
				inputFile >> Field[i][j];
			}
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i != 0 && j == 0) {
					addToMas(put, i, j);
					Field[i][j] += Field[i - 1][j];
				}
				if (i == 0 && j != 0) {
					addToMas(put, i, j);
					Field[i][j] += Field[i][j - 1];
				}
				if (i > 0 && j > 0) {
					addToMas(put, i, j);
					Field[i][j] = std::min(Field[i - 1][j], Field[i][j - 1]) + Field[i][j];
				}
			}
		}

		std::cout << Field[M - 1][N - 1] << '\n';
		for (int i = 0; i < put.size(); i++) {
			std::cout << put[i].x << ' ' << put[i].y << '\n';
		}
	}
	else
	{
		std::cout << "File not found!\n";
		return 1;
	}

	system("pause");
	return 0;
}