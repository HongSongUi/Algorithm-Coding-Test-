#include <bits/stdc++.h>
using namespace std;

bool compare(const tuple<int,int,string>&a , const tuple<int, int , string>& b)
{
	if (get<1>(a) == get<1>(b)) return get<0>(a) < get<0>(b);
	return get<1>(a) < get<1>(b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<tuple<int, int, string>> arr(n); // index , age , name
	int age = 0;
	string name = "";
	for (int i = 0; i < n; i++)
	{
		cin >> age >> name;
		arr[i] = make_tuple(i, age, name);
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < n; i++)
	{
		cout << get<1>(arr[i]) << ' ' << get<2>(arr[i]) << '\n';
	}
	return 0;
}