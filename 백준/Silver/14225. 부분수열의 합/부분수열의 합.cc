#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
set<int> sums; // 중복을 방지하기 위한 집합(set)
vector<bool> check(2000001, false);
vector<int> tmp;

void Calc(int index, int sum) 
{
    if (index == n)
    {
        if (sum > 0) check[sum] = true;
        return;
    }
    Calc(index + 1, sum + arr[index]);
    Calc(index + 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    Calc(0, 0);
    for (int i = 1; i < 2000001; i++)
    {
        if (check[i] == false)
        {
            cout << i;
            break;
        }
    }
    return 0;
}
