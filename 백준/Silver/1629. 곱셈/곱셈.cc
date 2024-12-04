#include <bits/stdc++.h>
using namespace std;


long long FindRemain(int bottom, int count, int num)
{
	if (count <=0)
	{
		return 1;
	}
	long long answer;
	if (count % 2 == 0)
	{
		long long temp = FindRemain(bottom, count / 2, num);
		answer = (temp * temp) % num;
	}
	else
	{
		long long temp = FindRemain(bottom, count - 1, num);
		answer = temp * bottom % num;
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	long long result = FindRemain(a, b, c);
	cout << result;
}