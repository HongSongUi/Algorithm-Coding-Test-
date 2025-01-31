#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> town;
vector<pair<int, int>> chicken;
vector<vector<int>> dist;
int sumMin = INT_MAX;
void Calc(const vector<int>& temp)
{
    int d = 0;
    for (int i = 0; i < town.size(); i++)
    {
        int t = INT_MAX;
        for (int j = 0; j < temp.size(); j++)
        {
            int index = temp[j];
            t = min(t, dist[i][index]);
        }
        d += t;
    }
    sumMin = min(sumMin, d);
}
void BackTraking(int start, vector<int>& temp)
{
    if (temp.size() == m)
    {
        Calc(temp);
        return;
    }
    for (int i = start; i < chicken.size(); i++)
    {
        temp.push_back(i);
        BackTraking(i + 1, temp);
        temp.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

   
    cin >> n >> m;

    int tCount = 0, mCount = 0;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            if (num == 1)
            {
                town.emplace_back(make_pair(j, i));
            }
            else if (num == 2)
            {
                chicken.emplace_back(make_pair(j, i));  
            }
        }
    }
    dist.resize(town.size(), vector<int>(chicken.size()));
    for (int i = 0; i < town.size(); i++)
    {
        for (int j = 0; j < chicken.size(); j++)
        {
            dist[i][j] = abs(town[i].first - chicken[j].first) + abs(town[i].second - chicken[j].second);
        }
    }
    
    vector<int> temp;
    BackTraking(0, temp);
   
    cout << sumMin;
    return 0;
}