#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

int main() {

	std::string file;
	std::cout << "Enter the name of the input file: ";
	std::cin >> file;
	std::ifstream inputFile(file);
	std::vector<int> mas;
	std::vector<int> sqrMas;
	std::vector<int> sum;

	if (inputFile.is_open()) {
		int N;
		bool found = false;
		inputFile >> N;
		for (int i = 1; i <= N; i++) {
			mas.push_back(i);
			sqrMas.push_back(i * i);
		}

		for (int i = 0; i < N; i++) {
			std::cout << mas[i] << '-' << sqrMas[i] << std::endl;
		}
		
		
		for (int i = 0; i < sqrMas.size(); i++) {
			for (int j = 0; j < sqrMas.size(); j++) {
				int a = sqrMas[i] + sqrMas[j];
				sum.push_back(a);
				std::cout << "Summa " << sqrMas[i] << " and " << sqrMas[j] << " = " << sum[sum.size() - 1] << '\n';
			}
		}

		for (int i = 0; i < sum.size(); i++) {
			
		}
	}
	else {
		std::cout << "File not found\n";
		return 1;
	}

	system("pause");
	return 0;
}