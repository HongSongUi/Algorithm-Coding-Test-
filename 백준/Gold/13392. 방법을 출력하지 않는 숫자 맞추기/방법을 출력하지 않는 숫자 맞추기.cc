#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10001;
const int MAX_ROT = 10;
int N;
string start, target;
vector<vector<int>> dp;
int solve(int pos, int rot) {
    // 기저 사례: 모든 자리를 다 확인했을 때
    if (pos == N) return 0;

    // 메모이제이션
    int& ret = dp[pos][rot];
    if (ret != -1) return ret;

    // 현재 숫자의 실제 값 계산 (누적 회전 적용)
    int curr = (start[pos] - '0' + rot) % 10;
    int dest = target[pos] - '0';

    // 왼쪽으로 돌리는 경우
    int left = (dest - curr + 10) % 10;
    // 오른쪽으로 돌리는 경우
    int right = 10 - left;

    // 최소값 계산
    ret = min(
        left + solve(pos + 1, (rot + left) % 10),  // 왼쪽으로 돌린 경우
        right + solve(pos + 1, rot)                // 오른쪽으로 돌린 경우
    );

    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> start >> target;

    dp.resize(N, vector<int>(MAX_ROT, -1));
    cout << solve(0, 0) << '\n';

    return 0;
}