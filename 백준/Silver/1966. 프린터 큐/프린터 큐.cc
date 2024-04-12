#include <bits/stdc++.h>
using namespace std;

struct Document
{
	
	int index = 0;
	int priority = 0;
};

bool FindFirst(deque<Document>& d, int p)
{
	int count = 0;
	for (int i = 1; i < d.size(); i++)
	{
		int temp = d[i].priority;
		if (temp > p)
		{
			return false;
		}
		else if (p == temp)
		{
			count++;
		}
	}
	if (count == (d.size()-1))
	{
		return true;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int number = 0;
	int find = 0;
	int priority = 0;
	int count = 0;
	cin >> n;

	int temp = 0;
	deque<Document> buff;
	

	while (count < n)
	{
		cin >> number >> find;
		for (int i = 0; i < number; i++)
		{
			cin >> priority;
			Document doc;
			doc.index = i;
			doc.priority = priority;
			buff.push_back(doc);
		}
		
		while (true)
		{
			int p = buff.front().priority;
			int i = -1;
			if (FindFirst(buff, p))
			{
				i = buff.front().index;
				buff.pop_front();
				temp++;
			}
			else
			{
				buff.push_back(buff.front());
				buff.pop_front();
			}
			if (i == find)
			{
				break;
			}
		}
		cout << temp << "\n";
		count++;
		temp = 0;
		while (!buff.empty()) buff.pop_front();
	}
}