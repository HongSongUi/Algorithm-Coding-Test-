#include <bits/stdc++.h>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0, m;

    cin >> n >> m;
    map<string, int> name;
    map<int, string> idx;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        name.insert(make_pair(s, i+1));
        idx.insert(make_pair(i+1, s));
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9')
        {
            int num = stoi(s);
            cout << idx[num] << '\n';
        }
        else
        {
            cout << name[s] << '\n';
        }
    }

    return 0;
}