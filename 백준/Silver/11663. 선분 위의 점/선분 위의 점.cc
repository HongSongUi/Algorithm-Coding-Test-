#include <bits/stdc++.h>
using namespace std;
vector<int> points;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    points.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> points[i];
    }
    sort(points.begin(), points.end());
    int startP;
    int endP;
    int answer = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> startP >> endP;
        answer = 0;
        int leftIdx = lower_bound(points.begin(), points.end(), startP) - points.begin();
        int rightIdx = upper_bound(points.begin(), points.end(), endP) - points.begin();
        answer = rightIdx - leftIdx;
        cout << answer << '\n';
    }
    return 0;
}