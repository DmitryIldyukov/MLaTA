#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool IsCorrectWord(std::string word, std::string mainWord, int& counter)
{
	std::sort(word.begin(), word.end());

	for (int i = 0; i < word.length(); i++) {
		std::string::iterator itr = std::find(mainWord.begin(), mainWord.end(), word[i]);
		if (itr == mainWord.end())
			return false;
		else
			mainWord.erase(itr);
	}	
	counter += word.length();
	return true;
}

int main()
{
	std::ifstream input("input7.txt");

	if (!input)
	{
		std::cout << "File is not exist!\n";
		return 1;
	}

	int counter = 0;
	std::string mainWord;
	input >> mainWord;
	std::string word;

	std::vector<std::string> words;

	while (input >> word) {
		if (IsCorrectWord(word, mainWord, counter))
			words.push_back(word);
	}

	std::sort(words.begin(), words.end(), [](const std::string& word1, const std::string& word2) {
		if (word1.length() != word2.length())
			return word1.size() > word2.size();
		return word1 < word2;
	});

	std::ofstream output("output.txt");
	output << counter << '\n';
	for (auto word : words)
		output << word << '\n';
	
	return 0;
}