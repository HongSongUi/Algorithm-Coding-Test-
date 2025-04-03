#include <bits/stdc++.h>
using namespace std;
int n = 0;
int answer = 0;
vector<int> arr;
vector<bool> isVaild(50 * 20 + 1, false);
void MakeNum(int index, int num,int depth)
{
    if (depth == n)
    {
        if (!isVaild[num])
        {
            isVaild[num] = true;
            answer++;
        }
        return;
    }
    for (int i = index; i < 4; i++)
    {
        MakeNum(i, num + arr[i], depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr = { 1,5,10,50 };
    MakeNum(0,0,0);
    cout << answer;
    return 0;
}