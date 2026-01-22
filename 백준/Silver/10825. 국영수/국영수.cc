#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct Student
{
	string name;
	int kor;
	int math;
	int eng;
};
bool cmp(Student a, Student b)
{
	if (a.kor == b.kor)
	{
		if (a.eng == b.eng)
		{
			if (a.math == b.math)
			{
				return a.name < b.name;
			}
			return a.math > b.math;
		}
		return a.eng < b.eng;
	}
		
	return a.kor > b.kor;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<Student> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i].name >> vec[i].kor >> vec[i].eng >> vec[i].math;
	}
	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		cout << vec[i].name << '\n';
	}
	return 0;
}
