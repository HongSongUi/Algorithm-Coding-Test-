#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    string result = "";
    while (n != 0) 
    {
        long long remainder = n % -2;
        n /= -2;

        if (remainder < 0) {
            remainder += 2;
            n += 1;
        }
        result += to_string(remainder);
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
    return 0;
}