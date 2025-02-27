#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;
	int m = 0;
	cin >> m;
	int num = 0;
	int dec = 0;
	int p = pow(a, m-1);
	int tmp = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		tmp = num * p;
		p /= a;
		dec += tmp;
	}
	stack<int> s;
	while (dec>0)
	{
		tmp = dec % b;
		s.push(tmp);
		dec /= b;
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}