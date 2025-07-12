#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int n = 0;

    cin >> n;
 
    set<pair<int, int>> easySet;
    set<pair<int, int>, greater<>> hardSet;

    unordered_map<int, int> p2l;

    int p, l = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> l;
        p2l[p] = l;
        easySet.insert(make_pair(l, p));
        hardSet.insert(make_pair(l, p));
    }
    int m = 0;
    cin >> m;
    string s = "";
    int num = 0;
    while (m--)
    {
        cin >> s;
        if (s == "recommend")
        {
            cin >> num;
            if (num == 1)
            {
                cout << hardSet.begin()->second << '\n';
            }
            else if (num == -1)
            {
                cout << easySet.begin()->second << '\n';
            }
        }
        else if (s == "add")
        {
            cin >> p >> l;
            p2l[p] = l;
            easySet.insert(make_pair(l, p));
            hardSet.insert(make_pair(l, p));
        }
        else if (s == "solved")
        {
            cin >> num;
            int tmp = p2l[num];
            p2l.erase(num);
            easySet.erase(easySet.find(make_pair(tmp,num)));
            hardSet.erase(hardSet.find(make_pair(tmp,num)));
        }
    }
    return 0;
}