#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 0;
    int k = 0;
    int root = 0;
    int parentIndex = 0;
    int answer = 0;
    while (true)
    {
        cin >> n >> k;
        if (n == 0 && k == 0)
        {
            break;
        }
        root = 0;
        parentIndex = -1;
        answer = 0;
        map<int, int> treeCount;
        vector<int> temp(n);
        vector<vector<int>> tree(n);
        map<int, int> child;
        for (int i = 0; i < n; i++)
        {
            cin >> temp[i];
        }
        root = temp[0];
        for (int i = 1; i < n; i++)
        {
            if (temp[i] - temp[i - 1] > 1)
            {
                parentIndex++;
            }
            tree[parentIndex].emplace_back(temp[i]);
            treeCount[temp[parentIndex]]++;
            child.insert(make_pair(temp[i], parentIndex));
        }
        int parentNum = temp[child[k]];
        if (parentNum == root)
        {
            cout << 0 << '\n';
            continue;
        }
        int parentDepth = child[parentNum];
       
        for (int i = 0; i < tree[parentDepth].size(); i++)
        {
            if (tree[parentDepth][i] != parentNum)
            {
                int num = tree[parentDepth][i];
                answer += treeCount[num];
            }
        }
        cout << answer << '\n';
    }
    return 0;
}