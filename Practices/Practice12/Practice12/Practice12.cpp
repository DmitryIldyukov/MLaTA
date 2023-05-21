#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool CharInString(string& str, char ch)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (ch == str[i])
			return true;
	}

	return false;
}

int main()
{
	ifstream input("input2.txt");
	ofstream output("output.txt");

	if (!input)
	{
		cout << "File is not exist" << endl;
		return 1;
	}

	long long lenghtStr;
	string nowLenghtString = "", mainString, maxLenghtString = "";

	input >> lenghtStr;
	input >> mainString;

	for (int i = 0; i < lenghtStr; i++)
	{
		for (int j = i; j < lenghtStr; j++)
		{
			if (!CharInString(nowLenghtString, mainString[j]))
				nowLenghtString += mainString[j];
			else
			{
				reverse(maxLenghtString.begin(), maxLenghtString.end());
				if (nowLenghtString.length() > maxLenghtString.length())
					maxLenghtString = nowLenghtString;
				break;
			}
		}
		nowLenghtString = "";
	}

	cout << maxLenghtString << endl;

	return 0;
}