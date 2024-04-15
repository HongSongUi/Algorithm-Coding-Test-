#include <bits/stdc++.h>
using namespace std;

struct Buffer
{
	int zero_count;
	int one_count;
	Buffer()
	{
		zero_count = 0;
		one_count = 0;
	}
	Buffer(int z, int o)
	{
		zero_count = z;
		one_count = o;
	}
	Buffer operator+ (Buffer& a)
	{
		return Buffer(zero_count + a.zero_count, one_count + a.one_count);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int num = 0;
	cin >> n;
	int zero_count = 0;
	int one_count = 0;
	vector<Buffer> buff(41);
	buff[0] = Buffer(1, 0);
	buff[1] = Buffer(0, 1);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		for (int j = 2; j <= num; j++)
		{
			buff[j] = buff[j - 1] + buff[j - 2];
		}
		cout << buff[num].zero_count << " " << buff[num].one_count << "\n";
	}
}