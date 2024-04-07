#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m = 0;
	int num = 0;
	int sum = 0;
	int result = 0;
	cin >> n >> m;
	vector<int> temp(n);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		temp[i] = num;
	}
	sort(temp.rbegin(), temp.rend());
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((temp[i] + temp[j]) >= m)
			{
				continue;
			}
			for (int p = j + 1; p < n; p++)
			{
				sum =temp[i] +temp[j] + temp[p];
				if (sum <= m&& sum>result)
				{
					result = sum;	
				}
			}
		}
	}
    cout<<result;
    return 0;
}	