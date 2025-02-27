#include <bits/stdc++.h>
using namespace std;
int n, m = 0;
vector<int> arr;

void Func(int len, int num)
{
	if (len == m)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++)
	{
		arr.emplace_back(i);
		Func(len + 1 , i);
		arr.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	Func(0,1);
	return 0;
}