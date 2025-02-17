#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 0;
    cin >> T;
    int answer = 0;
    long long  num = 0;
    for (int i = 0; i < T; i++)
    {
        cin >> num;
        answer = 0;
 
        while (num != 0)
        {
            answer = answer + (num / 5);
            num /= 5;
        }
        cout << answer << '\n';
    }
    return 0;
}