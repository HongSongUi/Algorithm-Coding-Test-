#include <bits/stdc++.h>

using namespace std;

struct Student
{
	string name;
	int kor;
	int eng;
	int math;
};

bool cmp(const Student& a , const Student& b)
{
	if (a.kor == b.kor &&  a.eng == b.eng && a.math == b.math)
	{
		return a.name  < b.name;
	}
	if (a.kor == b.kor && a.eng == b.eng)
	{
		return a.math > b.math;
	}
	if (a.kor == b.kor)
	{
		return a.eng <  b.eng;
	}
	return a.kor > b.kor;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n = 0;
	cin >> n;
	vector<Student> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].name << '\n';
	}
	return 0;
}