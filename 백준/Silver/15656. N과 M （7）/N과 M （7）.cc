#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 0;
vector<int> arr;
vector<int> tmp;
void Func()
{
    if (tmp.size() == m)
    {
        for (int i = 0; i < tmp.size(); i++)
        {
            cout << tmp[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        tmp.emplace_back(arr[i]);
        Func();
        tmp.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    Func();
    return 0;
}