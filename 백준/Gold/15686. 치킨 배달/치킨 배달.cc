/*
치킨집과 집 사이의 거리를 계산하는 문제이기 때문에 주어진 전체 graph를 전부 저장하지 않고 
집과 치킨집의 좌표만 저장
치킨집이 전체 K개라고 했을 때 그 중 주어진 m개만 선택 -> 조합 사용


*/

#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> tmp;

int answer = INT_MAX;

void FindDist(int count,int idx)
{
	if (count == m)
	{
		int total = 0;
		for (int i = 0; i < house.size(); i++) //각 집 별로 가장 가까운 치킨 집의 거리
		{
			int min_dist = INT_MAX;
			int x = house[i].first;
			int y = house[i].second;
			for (int j = 0; j < tmp.size(); j++)
			{
				int tx = tmp[j].first;
				int ty = tmp[j].second;
				int dist = abs(tx - x) + abs(ty - y);
				if (dist < min_dist)
				{
					min_dist = dist;
				}
			}
			total += min_dist;
		}
		answer = min(total, answer);
		return;
	}
	for (int i = idx; i < chicken.size(); i++)
	{

		tmp.emplace_back(make_pair(chicken[i].first, chicken[i].second)); // 저장
		FindDist(count + 1, i+1);
		tmp.pop_back(); // 상태 복구
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			if (num == 1)
			{
				house.emplace_back(make_pair(j, i));//집 좌표
			}
			else if (num == 2)
			{
				chicken.emplace_back(make_pair(j, i)); // 치킨집 좌표
			}
		}
	}
	FindDist(0,0);
	cout << answer;
	return 0;
}