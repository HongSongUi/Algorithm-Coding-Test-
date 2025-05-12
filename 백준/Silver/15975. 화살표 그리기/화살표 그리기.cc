#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
    map<int, vector<int>> points;

    for (int i = 0; i < n; i++) 
    {
        int pos, color;
        cin >> pos >> color;
        points[color].push_back(pos);
    }

    for (auto& p : points) 
    {
        sort(p.second.begin(), p.second.end());
    }

    long long answer = 0;

    for (auto& p : points)
    {
        vector<int>& positions = p.second;

        if (positions.size() <= 1) continue;

        answer += positions[1] - positions[0];


        for (int i = 1; i < positions.size() - 1; i++) 
        {
            int leftDist = positions[i] - positions[i - 1];
            int rightDist = positions[i + 1] - positions[i];
            answer += min(leftDist, rightDist);
        }

        answer += positions[positions.size() - 1] - positions[positions.size() - 2];
    }

    cout << answer << '\n';
	return 0;
}