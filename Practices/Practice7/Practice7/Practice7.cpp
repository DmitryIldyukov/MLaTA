#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

bool checkProgression(vector<int> vec)
{
	if (vec.size() == 1)
		return true;
	int step = vec[1] - vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] - vec[i - 1] != step)
			return false;
	}
	return true;
}

int main()
{
	ifstream input("in5.txt");
	if (!input)
	{
		cout << "File is not found!\n";
		return 1;
	}
	ofstream output("output.txt");

	int N, count;
	input >> N;

	for (int i = 0; i < N; i++)
	{
		input >> count;
		vector<int> vec;
		for (int j = 0; j < count; j++)
		{
			int num;
			input >> num;
			vec.push_back(num);
		}
		sort(vec.begin(), vec.end());
		if (checkProgression(vec))
			output << "Yes\n";
		else
			output << "No\n";
	}

	return 0;
}