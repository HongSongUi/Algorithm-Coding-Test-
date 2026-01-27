#include <bits/stdc++.h>

using namespace std;

vector<int> numbers;
vector<int> opers;
vector<string> choose;
map<int, string> tmp;
int max_val = INT_MIN;
int min_val = INT_MAX;
void Calc()
{
	int cur_num = numbers[0];
	int next_num = 0;
	string oper = "";
	for (int i = 1; i < numbers.size(); i++)
	{
		next_num = numbers[i];
		oper = choose[i-1];
		if (oper == "+")
		{
			cur_num += next_num;
		}
		else if (oper == "-")
		{
			cur_num -= next_num;
		}
		else if (oper == "*")
		{
			cur_num *= next_num;
		}
		else if (oper == "/")
		{
			cur_num /= next_num;
		}
	}
	min_val = min(min_val, cur_num);
	max_val = max(max_val, cur_num);
	return;
}

void BackTracking(int cnt, int limit)
{
	if (cnt == limit)
	{
		Calc();
		return;
	}
	for (int i = 0; i < opers.size(); i++)
	{
		if (opers[i] > 0)
		{
			choose.emplace_back(tmp[i]);
			opers[i]--;
			BackTracking(cnt + 1, limit);
			opers[i]++;
			choose.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	numbers.resize(n);
	opers.resize(4);
	int limit = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> opers[i];
		limit += opers[i];
	}
	tmp[0] = "+";
	tmp[1] = "-";
	tmp[2] = "*";
	tmp[3] = "/";
	BackTracking(0, limit);
	cout << max_val << '\n' << min_val;
	return 0;
}
