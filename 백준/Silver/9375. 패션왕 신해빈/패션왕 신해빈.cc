#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;

	int num = 0;
	int count = 1;
	while (n > 0)
	{
        map<string, int> clothes;
		cin >> num;
		string name = "";
		string type = "";
		for (int i = 0; i < num; i++)
		{
			cin >> name >> type;
			clothes[type]++;
		}
		for (auto iter : clothes)
		{
			count *= (iter.second+1);
		}
		count--;
		cout << count << "\n";
		count = 1;
		n--;
	}
}