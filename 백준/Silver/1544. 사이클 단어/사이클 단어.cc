#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    queue<string> words;
    vector<string> result;

    string str = "";
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        words.push(str);
    }
    while (!words.empty())
    {
        str = words.front();
        words.pop();
        if (result.size() == 0)
        {
            result.emplace_back(str);
            continue;
        }
        bool isEqual = false;
        for (int i = 0; i < result.size(); i++)
        {
            string target = result[i];
            for (int j = 0; j < target.size(); j++)
            {
                string tmp = target.substr(j, target.size()) + target.substr(0, j);
                if (tmp == str)
                {
                    isEqual = true;
                    break;
                }
            }
            if (isEqual) break;
        }
        if (!isEqual)
        {
            result.emplace_back(str);
        }
    }
    cout << result.size();
    return 0;
}