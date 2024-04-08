#include <iostream>
#include <algorithm>
using namespace std;

bool Compare(string a, string b)
{
	if (a.length() == b.length())
	{
		return a < b;
	}
	else
	{
		return a.length() < b.length();
	}
}
int main()
{
	int count = 0;
	string temp = "";
	cin >> count;
	vector<string> words(count);
	for (int i = 0; i < count; i++)
	{
		cin >> temp;
		words[i] = temp;
	}
	sort(words.begin(), words.end(), Compare);
	for (int i = 0; i < count; i++)
	{
		if (i != 0)
		{
			if (words[i] == words[i - 1])
			{
				continue;
			}
		}
		cout << words[i] << endl;
	}
}
