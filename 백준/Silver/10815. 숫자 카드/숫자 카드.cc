/*
접근법 : 가지고 있는 카드를 arr에 저장, 그 후 찾는 값이 arr에 있으면 1, 없으면 0 
수의 범위를 -10,000,000 ~ 10,000,000 를 0~ 20,000,000으로 변경
시간 복잡도 : O(n + m)
*/
#include <bits/stdc++.h>
using namespace std;
#define INF  10000000
vector<bool> arr(20000001, false);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    int card = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> card;
        card += INF;
        arr[card] = true;
    }
    int m = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> card;
        card += INF;
        cout << arr[card] << ' ';
    }
}