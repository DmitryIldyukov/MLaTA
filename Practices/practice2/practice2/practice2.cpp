#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int max = 200;

bool CheckCorrectInputFile(std::string file) {
	std::ifstream inputFile;
	inputFile.open(file);

	if (inputFile.is_open())
		return true;
	return false;
}

void Metka(int i, int j, std::vector<std::vector<char>>& field, int width, int height) 1{
	if (field[i][j] == '#') {
		field[i][j] = '.';
		if (i != width - 1) {
			Metka(i + 1, j, field, width, height);
		}
		if (i != 0) {
			Metka(i - 1, j, field, width, height);
		}
		if (j != height - 1) {
			Metka(i, j + 1, field, width, height);
		}
		if (j != 0) {
			Metka(i, j - 1, field, width, height);
		}
	}
}

int main() {

	setlocale(LC_ALL, "rus");
	std::string file;
	std::cout << "Введите название входного файла: ";
	std::cin >> file;

	if (CheckCorrectInputFile(file)) {
		std::ifstream inputFile;
		inputFile.open(file);

		int counter = 0;
		int width;
		int height;

		inputFile >> width;
		inputFile >> height;
		std::vector<std::vector<char>> field(width, std::vector<char>(height));

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				inputFile >> field[i][j];
			}
		}

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				if (field[i][j] == '#') {
					Metka(i, j, field, width, height);
					counter++;
				}
			}
		}

		std::cout << counter << '\n';
	}
	else {
		std::cout << "Введенный файл не найден!\n";
		system("pause");
		return 1;
	}

	system("pause");
	return 0;
}