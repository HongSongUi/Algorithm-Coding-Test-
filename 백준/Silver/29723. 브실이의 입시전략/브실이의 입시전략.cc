#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    int limit = m - k;
    map<string, int> score;
    vector<int>arr;
    int max_score = 0;
    int min_score = 0;
    string s = "";
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> num;
        score.insert(make_pair(s, num));

    }
    for (int i = 0; i < k; i++)
    {
        cin >> s;
        max_score += score[s];
        min_score += score[s];
        score.erase(s);
    }
    for (auto data : score)
    {
        arr.emplace_back(data.second);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < limit; i++)
    {
        min_score += arr[i];
    }
    int start = arr.size()-1;
    limit = start - limit;
    for (int i = start; i > limit; i--)
    {
        max_score += arr[i];
    }
    cout << min_score << ' ' << max_score;
    return 0; 
}