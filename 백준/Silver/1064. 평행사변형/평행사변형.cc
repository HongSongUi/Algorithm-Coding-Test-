#include <bits/stdc++.h>
using namespace std;

double dist(pair<int, int> a, pair<int, int> b) 
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
bool isColiner(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    pair<int, int> AB = make_pair(b.first - a.first, b.second - a.second);
    pair<int, int> AC = make_pair(c.first - a.first, c.second - a.second);

    int cross = (AB.first * AC.second) - (AC.first * AB.second);

    return cross == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, int> a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    if (isColiner(a, b, c ))
    {
        cout << -1;
        return 0;
    }


    double d1 = 2 * (dist(a, b) + dist(a, c));
    double d2 = 2 * (dist(a, b) + dist(b, c));
    double d3 = 2 * (dist(a, c) + dist(b, c));

    double result = max({ d1,d2,d3 }) - min({ d1,d2,d3 });

    cout << fixed;
    cout.precision(16);
    cout << result;

    return 0;
}