#include <bits/stdc++.h>
using namespace std;

bool compare(const string& a, const string& b) 
{
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;

    cin >> n;
    string s = "";
    vector<string> arr;
    while (n--)
    {
        cin >> s;
        string tmp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] - '0' >= 0) && (s[i] - '0' <= 9))
            {
                tmp += s[i];
            }
            else
            {          
                if (tmp != "")
                {
                    while (tmp.size() > 1 && tmp[0] == '0')
                    {
                        tmp.erase(tmp.begin());
                    }
                    arr.emplace_back(tmp);
                    tmp = "";
                }                    
            }       
        }
        if (tmp != "")
        {
            while (tmp.size() > 1 && tmp[0] == '0')
            {
                tmp.erase(tmp.begin());
            }
            arr.emplace_back(tmp);
        }
    }
    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\n';
    }
    return 0;
}
