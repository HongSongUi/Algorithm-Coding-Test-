#include <bits/stdc++.h>
using namespace std;

struct Stat 
{
	int index;
	int height;
	int weight;
	int rank;
	Stat()
	{
		index = 0;
		height = 0;
		weight = 0;
		rank = 0;
	}
	bool operator== (Stat& s)
	{
		if (this->index == s.index)
		{
			return true;
		}
		return false;
	}
	bool operator>(Stat& s)
	{
		if ((this->height > s.height) && (this->weight > s.weight))
		{
			return true;
		}
		return false;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 0;
	cin >> num;
	int rank = 0;
	vector<Stat> buff(num);

	for (int i = 0; i < num; i++)
	{
		Stat s;
		cin >> s.weight >> s.height;
		s.index = i;
		buff[i] = s;
	}
	for (int i = 0; i < num; i++)
	{
		Stat temp = buff[i];
		rank = 0;
		for (int j = 0; j < num; j++)
		{
			if (temp == buff[j])
			{
				continue;
			}
			if (buff[j] >temp)
			{
				rank++;
			}
		}
		buff[i].rank = rank + 1;
	}
	for (int i = 0; i < num; i++)
	{
		cout << buff[i].rank << " ";
	}
}