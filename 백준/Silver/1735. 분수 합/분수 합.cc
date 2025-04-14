#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int r = 0;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num1 = 0, num2 = 0;
    int num3 = 0, num4 = 0;

    cin >> num1 >> num2 >> num3 >> num4;
    
    int answer1 = 0, answer2 = 0;
    answer1 = (num1 * num4) + (num2 * num3);
    answer2 = num2 * num4;
    int g = gcd(answer1, answer2);
    if (g == 1)
    {
        cout << answer1 << " " << answer2;
    }
    else
    {
        cout << answer1 / g << ' ' << answer2 / g;
    }
}