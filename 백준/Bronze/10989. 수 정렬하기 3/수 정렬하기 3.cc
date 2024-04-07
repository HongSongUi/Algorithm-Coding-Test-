#include <iostream>
#include <vector>

using namespace std;

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n = 0;
	cin >> n;
	vector<int> temp(10001);
	
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		temp[num] += 1;
	}
	for (int i = 1; i < 10001; i++)
	{
		for (int j = 0; j < temp[i]; j++)
		{
			cout << i<< "\n";
		}
	}
}