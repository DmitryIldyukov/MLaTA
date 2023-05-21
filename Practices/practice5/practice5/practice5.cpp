#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream input("input5.txt");
    if (!input)
    {
        std::cout << "File is not exist\n";
        return 1;
    }

    std::ofstream output("out.txt");

    int N;
    input >> N;

    std::vector<int> inputVec;
    std::vector<int> numbers;
    std::vector<int> outputVec;

    for (int i = 0; i < N; i++)
    {
        int temp;
        input >> temp;
        inputVec.push_back(temp);
        numbers.push_back(i + 1);
        outputVec.push_back(i);
    }

    for (int i = N - 1; i >= 0; --i)
    {
        int temp = inputVec[i];
        outputVec[i] = numbers[i - temp];
        std::vector<int> tempVec;
        for (int j = 0; j < numbers.size(); j++)
        {
            if (numbers[j] != numbers[i - temp])
                tempVec.push_back(numbers[j]);
        }
        numbers = tempVec;
    }

    for (int i = 0; i < N; i++)
        output << outputVec[i] << ' ';

    return 0;
}