#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string duck = "quack";
    string s = "";
    cin >> s;
    vector<pair<char, bool>> tmp(s.length());
    int count = s.length();
    for (int i = 0; i < s.length(); i++)
    {
        tmp[i] = make_pair(s[i], true);
    }
    int idx = 0;
    int answer = 0;
    while (count != 0)
    {
        idx = 0;
        string str = "";
        for (int i = 0; i < tmp.size(); i++)
        {
            idx %= 5;
            char word = tmp[i].first;
            bool isChoose = tmp[i].second;
            if (isChoose && word == duck[idx])
            {
                idx++;
                tmp[i].second = false;
                count--;
                str = str + word;
            }
        }
        if (str.length() % 5 != 0 || str.length() == 0)
        {
            cout << -1;
            return 0;
        }
        else
        {
            answer++;
        }
    }
    cout << answer;
    return 0;
}