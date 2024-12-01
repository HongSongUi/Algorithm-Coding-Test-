#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> result;

void Combination(int start, int depth) {
    if (depth == m) 
    {
        for (int num : result) 
        {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++) 
    { 
        result.push_back(i);
        Combination(i, depth + 1); 
        result.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    Combination(1, 0);
}