#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;
	vector<int> arr(N);
	vector<int> buff(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		buff[i] = arr[i];
	}
	sort(buff.begin(), buff.end());
	buff.erase(unique(buff.begin(), buff.end()), buff.end());
	for (int i = 0; i < arr.size(); i++)
	{
		cout << lower_bound(buff.begin(), buff.end(), arr[i])- buff.begin() << " ";
	}

}