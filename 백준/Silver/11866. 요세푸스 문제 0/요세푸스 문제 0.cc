#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, k = 0;
	cin >> n >> k;
	queue<int> temp;
	cout << "<";
	for (int i = 0; i < n; i++)
	{
		temp.push(i + 1);
	}
	while (true)
	{
		if (temp.size() == 1)
		{
			cout << temp.front() << ">";
			temp.pop();
			break;
		}
		for (int i = 0; i < k-1; i++)
		{
			temp.push(temp.front());
			temp.pop();
		}
		cout << temp.front() << ", ";
		temp.pop();
	}
}