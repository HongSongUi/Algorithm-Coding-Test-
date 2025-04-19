#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, c, w = 0;
    cin >> n >> c >> w;
    int l = 0;
    long long answer = 0;
    vector<int> trees(n);
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }
   
    int count, cost = 0;
    int tmp = 0;
    long long tree_length = 0;
    long long money = 0;
    for (long long i = 1; i <= 10000; i++)
    {
        money = 0;
        tree_length = i;
        for (int j = 0; j < trees.size(); j++)
        {
            count = trees[j] / tree_length;
            cost = (trees[j] - 0.5) / tree_length;
            tmp = tree_length * count * w -c *cost;
            if (tmp > 0)
            {
                money += tmp;
            }
        }
        answer = max(answer, money);
    }
    
    cout << answer;

    return 0;
}