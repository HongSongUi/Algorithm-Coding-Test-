#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    
    cin >> n;

    int len = 0;
    vector<int> arr(n);
    vector<int> isStack(n);
    deque<int> dq;
    for(int i = 0; i<n; i++)
    {
        cin >> isStack[i];
    }
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (isStack[i] == false)
        {
            dq.push_back(arr[i]);
        }
    }
    cin >> len;
    int answer = 0;
    
    for (int i = 0; i < len; i++)
    {
        cin >> num;
        if (dq.size() == 0)
        {
            cout << num << " ";
        }
        else
        {
            cout << dq.back()<<" ";
            dq.pop_back();
            dq.push_front(num);
        }
    }
    return 0;
}