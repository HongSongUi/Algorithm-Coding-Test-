#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 0;
	int num = 0;
	int data = 0;
	cin >> count;

	string input_text = "";
	while (count > 0)
	{
		multiset<int> temp;
		cin >> num;
		while (num > 0)
		{
			cin >> input_text >> data;
			if (input_text == "I")
			{
				temp.insert(data);
			}
			else if (input_text == "D")
			{
				if (temp.size() != 0)
				{
					if (data == -1)
					{
						temp.erase(temp.begin());
					}
					else
					{
						temp.erase(prev(temp.end()));
					}
				}
			}
			num--;
		}
		if (temp.size() == 0)
		{
			cout << "EMPTY" << '\n';
		}
		else
		{
			cout << *prev(temp.end()) << " " << *temp.begin() << '\n';
		}
		count--;
	}
}