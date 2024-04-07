#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int count = 0;
	cin >> count;
	vector<int> temp(count);
	for (int i = 0; i < count; i++)
	{
		cin >> temp[i];
	}
	sort(temp.begin(), temp.end());
	for (int i = 0; i < count; i++)
	{
		cout << temp[i] <<"\n";
	}
	int a = 0;
}