#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s = "";
    cin >> s;
    map<string, int> tmp;
    for (int i = 1; i < s.length(); i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            if (j + i <= s.length())
            {
                string t = s.substr(j, i);
                tmp[t]++;
            }      
            else
            {
                break;
            }
        }
    }
    cout << tmp.size()+1;
    return 0;
}