#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    queue<int> q;
    int max_len = 0;
    int num = 0;
    int student = 0;
    int last = 0;
    while (n--)
    {
        cin >> num;
        if (num == 1)
        {
            cin >> student;
            q.push(student);
            if (q.size() > max_len)
            {
                max_len = q.size();
                last = q.back();
            }
            else if (q.size() == max_len)
            {
                if (last > q.back())
                {
                    last = q.back();
                }
            }
        }
        else if (num == 2)
        {
            q.pop();
        }
    }

    cout << max_len << ' ' << last;
    return 0;
}