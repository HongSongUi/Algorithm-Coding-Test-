#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b)
{
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    vector<int> tree(n);
    vector<pair<int, int>> temp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        temp[i] = make_pair(tree[i], num);
    }
    sort(temp.begin(), temp.end(), compare);
    long long answer = 0;
    for (int day = 0; day <n; day++)
    {
        answer = answer + (temp[day].first + temp[day].second * day);
    }
    cout << answer;
    return 0;
}