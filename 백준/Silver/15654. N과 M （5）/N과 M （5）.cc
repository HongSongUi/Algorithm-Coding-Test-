#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> result;
vector<int> arr;

void Combination(int start, int depth) 
{
    if (depth == m) 
    {
        for (int num : result) 
        {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < arr.size(); i++) 
    {
        if (find(result.begin(), result.end(), arr[i]) == result.end())
        {
            result.push_back(arr[i]);
            Combination(i + 1, depth + 1);
            result.pop_back();
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    Combination(0, 0);
}