#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr(10, 0);
    string roomNum = "";
    cin >> roomNum;
    for (int i = 0; i < roomNum.length(); i++)
    {
        int num = roomNum[i] - '0';
        if (num == 6)
        {
            arr[9]++;
        }
        else
        {
            arr[num]++;
        }
    }
    arr[9] = arr[9] / 2 + arr[9] % 2;
    cout << *max_element(arr.begin(), arr.end());
    return 0;
}