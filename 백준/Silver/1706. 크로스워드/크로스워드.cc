#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int r = 0, c = 0;
	cin >> r >> c;
	string p = "";
	vector<vector<char>> cross(r, vector<char>(c));
	for (int i = 0; i < r; i++)
	{
		cin >> p;
		for (int j = 0; j < c; j++)
		{
			cross[i][j] = p[j];
		}
	}
	vector<string> words;
	string tmp = "";
	for (int i = 0; i < r; i++)
	{
		tmp = "";
		for (int j = 0; j < c; j++)
		{
			if (cross[i][j] != '#')
			{
				tmp += cross[i][j];
			}
			else if (cross[i][j] == '#')
			{
				if (tmp.length() >= 2)
				{
					words.emplace_back(tmp);		
				}
				tmp = "";
			}
		}
		if (tmp.length() >= 2)
		{
			words.emplace_back(tmp);
		}
	}
	for (int i = 0; i < c; i++)
	{
		tmp = "";
		for (int j = 0; j < r; j++)
		{
			if (cross[j][i] != '#')
			{
				tmp += cross[j][i];
			}
			else if (cross[j][i] == '#')
			{
				if (tmp.length() >= 2)
				{
					words.emplace_back(tmp);
				}
				tmp = "";
			}
		}
		if (tmp.length() >= 2)
		{
			words.emplace_back(tmp);
		}
	}
	sort(words.begin(), words.end());
	cout << words[0];
	return 0;
}