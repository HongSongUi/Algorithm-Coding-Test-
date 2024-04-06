#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int num = 0;
	string result = "";
	vector<int> asc = { 1,2,3,4,5,6,7,8 };
	vector<int> des = { 8,7,6,5,4,3,2,1 };
	vector<int> temp;
	temp.resize(8);
	for (int i = 0; i < 8; i++)
	{
		cin >> num;
		temp[i]= num;
	}
	if (temp == asc)
	{
		result = "ascending";
	}
	else if (temp == des)
	{
		result = "descending";
	}
	else
	{
		result = "mixed";
	}
	cout << result;
}