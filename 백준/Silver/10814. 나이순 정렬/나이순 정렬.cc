#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct MemberData
{
	int Index;
	int Age;
	string Name;
	MemberData()
	{
		Index = 0;
		Age = 0;
		Name = "";
	}
	MemberData(int index ,int age, string name)
	{
		Index = index;
		Age = age;
		Name = name;
	}
};
bool Compare(MemberData a, MemberData b)
{
	if(a.Age == b.Age)
	{
		return a.Index < b.Index;
	}
	else
	{
		return a.Age < b.Age;
	}
}
int main()
{
	int count = 0;
	int age = 0;
	string name = "";
	cin >> count;
	vector<MemberData> DataArray(count);
	for (int i = 0; i < count; i++)
	{
		cin >> age;
		cin >> name;
		MemberData data(i,age, name);
		DataArray[i] = data;
	}
	sort(DataArray.begin(), DataArray.end(), Compare);
	for (int i = 0; i < count; i++)
	{
		cout << DataArray[i].Age << " " << DataArray[i].Name << "\n";
	}
}