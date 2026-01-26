#include <bits/stdc++.h>

using namespace std;

int n;
int min_value = INT_MAX;
vector<bool> visited;

void Calc(vector<vector<int>>vec)
{
	vector<int>s;
	vector<int>l;
	for (int i = 0; i < n; i++)
	{
		if (visited[i]) s.emplace_back(i);
		else l.emplace_back(i);
	}
	int s_num = 0;
	int l_num = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int st = s[i];
		int lt = l[i];
		for (int j = 0; j < s.size(); j++)
		{
			int sn = s[j];
			int ln = l[j];
			s_num += vec[st][sn];
			l_num += vec[lt][ln];
		}
	}
	int diff = s_num - l_num;
	min_value = min(min_value, abs(diff));
	return;
}
void BackTracking(int cnt,  int idx ,vector<vector<int>> vec)
{
	if (cnt == (n/2))
	{
		Calc(vec);
		return;
	}
	for (int i = idx; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			BackTracking(cnt + 1, i + 1, vec);
			visited[i] = false;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n;
	visited.resize(n);
	vector<vector<int>> vec(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> vec[i][j];
		}
	}
	BackTracking(0, 0, vec);
    cout << min_value;
	return 0;
}
