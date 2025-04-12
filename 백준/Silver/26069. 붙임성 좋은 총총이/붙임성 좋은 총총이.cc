#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    map<string, bool> dance;
    dance["ChongChong"] = true;
    string left, right;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> left >> right;
        if (dance[left])
        {
            if(!dance[right])
            {
                dance[right] = true;
                count++;
            }
           
        }
        else if (dance[right])
        {
            if (!dance[left])
            {
                dance[left] = true;
                count++;
            }
        }
    }
    cout << count;
}