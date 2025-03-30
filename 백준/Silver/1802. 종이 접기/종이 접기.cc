#include <bits/stdc++.h>
using namespace std;

bool isVaild(string& str, int left, int right)
{
    if (left >= right) return true;

    int mid = (left + right) / 2;

    for (int i = 0; i < mid - left; i++)
    {
        if (str[left + i] == str[right - i])
        {
            return false;
        }
    }

    return isVaild(str, left, mid - 1) && isVaild(str, mid + 1, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    while (n--)
    {
        string s = "";
        cin >> s;
        if (s.length() == 1)
        {
            cout << "YES" << '\n';
            continue;
        }
        if (isVaild(s, 0, s.length() - 1))
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
