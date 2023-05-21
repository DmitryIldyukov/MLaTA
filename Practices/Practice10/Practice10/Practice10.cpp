#include <iostream>
#include <fstream>

int main() 
{
	std::ifstream input("input.txt");
	if (!input)
	{
		std::cout << "File is not exist!\n";
		return 1;
	}

	int M, P, Q;
	input >> M;

	if (M < 1 || M > 5)
	{
		std::cout << "Invalid argument!\n";
		return 1;
	}

	for (int i = 0; i < M; i++)
	{
		input >> P >> Q;
		if (P > 100000 || Q > 100000) 
		{
			std::cout << "Invalid arguments!\n";
			return 1;
		}
		if (P % 2 == 0 || Q % 2 == 0)
			std::cout << 1 << std::endl;
		else 
			std::cout << 2 << std::endl;
	}

	return 0;
}