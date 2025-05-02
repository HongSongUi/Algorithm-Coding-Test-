#include <bits/stdc++.h>
using namespace std;

struct Medal
{
    int g;
    int s;
    int b;
    Medal(int g, int s, int b)
    {
        this->g = g;
        this->s = s;
        this->b = b;
    }
};
bool SortMedal(pair<Medal,int>& a , pair<Medal,int>&b)
{
    if (a.first.g != b.first.g) return a.first.g > b.first.g;
    if (a.first.s != b.first.s) return a.first.s > b.first.s;
    return a.first.b > b.first.b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0, k = 0;
    cin >> n >> k;
    
    vector<pair<Medal, int>> rank;

    int num = 0;
    int g = 0;
    int s = 0;
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num >> g >> s >> b;
        rank.emplace_back(make_pair(Medal(g, s, b), num));
    }
    sort(rank.begin(), rank.end(), SortMedal);
    int result = 1;
    map<int, int> tmp;
    tmp[rank[0].second] = 1;

    for (int i = 1; i < n; i++)
    {
        if (rank[i].first.g == rank[i - 1].first.g &&
            rank[i].first.s == rank[i - 1].first.s &&
            rank[i].first.b == rank[i - 1].first.b) {
            tmp[rank[i].second] = result;
        }
        else {
            result = i + 1;
            tmp[rank[i].second] = result;
        }
    }
    cout << tmp[k];
    return 0; 
}