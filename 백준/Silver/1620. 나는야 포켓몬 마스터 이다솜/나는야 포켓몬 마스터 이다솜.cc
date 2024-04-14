#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int k = 0;
	cin >> n >> k;
	string name = "";
	map<string, int> name_buff;
	map<int, string> id_buff;
	int find_id = 0;
	string find_name = "";
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		name_buff.insert(make_pair(name, i + 1));
		id_buff.insert(make_pair(i + 1, name));
	}
	for (int i = 0; i < k; i++)
	{
		cin >> name;
		if (name[0] >= 'A' && name[0] <= 'Z')
		{
			find_id = name_buff[name];
			cout << find_id << "\n";
		}
		else
		{
			int temp = stoi(name);
			find_name = id_buff[temp];
			cout << find_name << "\n";
		}
	}
}