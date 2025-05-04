#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int start = 0;
    int right = 0;
    int min_count = INT_MAX;
    int limit_num = arr[0] + 4;
    while (right < arr.size())
    {
        if (arr[right] <= limit_num)
        {
            right++;
         
        }
        else
        {
            int tmp = 5 - (right - start);
            if (tmp < min_count)
            {
                min_count = tmp;
            }
            start++;
            right = start;
            limit_num = arr[start] + 4;
        }
    }
    int tmp = 5 - (right - start);
    if (tmp < min_count)
    {
        min_count = tmp;
    }

    cout << min_count;
 
    return 0; 
}