#include <bits/stdc++.h>
using namespace std;

int BFS(int point, int M ,queue<pair<int, int>>& q, vector<bool>& visit)
{
	while (!q.empty())
	{
		int point = q.front().first;
		int depth = q.front().second;
		q.pop();
		int back = point - 1;
		int front = point + 1;
		int doub = point * 2;
		if (point == M)
		{
			return depth;
		}
		if ((back >= 0 && back <= 100000) && visit[back] == false)
		{
			q.push(make_pair(back,depth+1));
			visit[back] = true;
		}
		if ((front >= 0 && front <= 100000) && visit[front] == false)
		{
			q.push(make_pair(front, depth + 1));
			visit[front] = true;
		}
		if ((doub >= 0 && doub <= 100000) && visit[doub] == false)
		{
			q.push(make_pair(doub, depth + 1));
			visit[doub] = true;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> visit(100001 , false);
	queue<pair<int, int>> q;
	int N, M = 0;
	cin >> N >> M;
	q.push(make_pair(N, 0));
	visit[N] = true;
	int result = BFS(N, M, q, visit);
	cout << result;
	int a = 0;
}