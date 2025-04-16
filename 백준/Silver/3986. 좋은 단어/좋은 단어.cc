#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    string s = "";
    int answer = 0;
    while (n--)
    {
        cin >> s;
        if (s.length() % 2 == 1) continue;
        stack<char> buff;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (buff.empty())
            {
                buff.push(s[i]);
            }
            else if (buff.top() == s[i])
            {
                buff.pop();
            }
            else
            {
                buff.push(s[i]);
            }
        }
        if (buff.empty())
        {
            answer++;
        }
      
    }
    cout << answer;
    return 0;
}