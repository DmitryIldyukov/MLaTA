#include <iostream>
#include <vector>
#include <fstream>

struct Vertex {
	int x, y;
};

int main()
{
	std::ifstream input("in3.txt");
	if (!input)
	{
		std::cout << "File is not open!\n";
		return 1;
	}
	std::ofstream output("output.txt");

	int numberOfVertices = 0, counterLeft = 0, counter—orner = 0;

	input >> numberOfVertices;

	std::vector<Vertex> vec;

	for (int i = 0; i < numberOfVertices; i++)
	{
		int x, y;
		input >> x;
		input >> y;
		vec.push_back({ x, y });
	}

	for (int i = 1; i < numberOfVertices - 1; i++)
	{
		if ((vec[i].x - vec[i - 1].x)*(vec[i + 1].y - vec[i - 1].y) - (vec[i].y - vec[i - 1].y) * (vec[i + 1].x - vec[i - 1].x) > 0) 
			counterLeft++;
		if ((vec[i].x - vec[i - 1].x) * (vec[i + 1].x - vec[i].x) + (vec[i].y - vec[i - 1].y) * (vec[i + 1].y - vec[i].y) == 0)
			counter—orner++;
	}

	output << counterLeft << ' ' << counter—orner << '\n';

	return 0;
}