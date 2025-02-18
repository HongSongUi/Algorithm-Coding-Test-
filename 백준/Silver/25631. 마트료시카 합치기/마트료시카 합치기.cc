#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    vector<int> temp(n);
    vector<bool> empty(n, false);
    int answer = n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];
    }
    sort(temp.begin(), temp.end());
    int num = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        num = temp[i];
        for (int j = i+1 ; j < temp.size(); j++)
        {
            if ( num < temp[j] && empty[j] == false)
            {
                empty[j] = true;
                answer--;
                break;
            }
        }
    }
    cout << answer;
    return 0;
}