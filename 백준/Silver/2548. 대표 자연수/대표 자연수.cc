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
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];

    }
    sort(temp.begin(), temp.end());
    int num = 0;
    int answer = 0;
    int maxVal = INT_MAX;
    for (int i = temp[n-1]; i >= 1; i--)
    {
        num = 0;
        for (int j = 0; j < n; j++)
        {
            num = num + abs(temp[j] - i);
        }
        if (num <= maxVal)
        {
            maxVal = num;
            answer = i;
        }
    }
    cout << answer;
    return 0;
}