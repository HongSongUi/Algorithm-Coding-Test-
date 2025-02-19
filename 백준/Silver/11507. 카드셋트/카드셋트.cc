#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "";
    map<string, int> cards;

    cin >> s;
    string t = "";
    int pCount = 13;
    int kCount = 13;
    int hCount = 13;
    int tCount = 13;
    for (int i = 0; i < s.length(); i += 3)
    {
        t = s.substr(i, 3);
        cards[t]++;
        if (cards[t] > 1)
        {
            cout << "GRESKA";
            return 0;
        }
        if (s[i] == 'P') pCount--;
        else if (s[i] == 'K') kCount--;
        else if (s[i] == 'H') hCount--;
        else tCount--;
    }

    cout << pCount << " " << kCount << " " << hCount << " " << tCount;
    return 0;
}