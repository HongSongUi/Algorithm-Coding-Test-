#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, count = 0;
    cin >> n;
    int input1, input2, input3 = 0;


    cin >> input1 >> input2 >> input3;
    vector<int> dp_max(3,0);
    vector<int> dp_min(3,0);
    dp_max[0] = input1;
    dp_max[1] = input2;
    dp_max[2] = input3;

    dp_min[0] = input1;
    dp_min[1] = input2;
    dp_min[2] = input3;
    int num1, num2, num3 = 0;

    for (int i = 1; i < n; i++)
    {
        cin >> input1 >> input2 >> input3;
        num1 = dp_max[0];
        num2 = dp_max[1];
        num3 = dp_max[2];

        dp_max[0] = max(num1, num2) + input1;
        dp_max[1] = max({ num1 , num2  , num3 }) + input2;
        dp_max[2] = max(num2 , num3 ) + input3;

        num1 = dp_min[0];
        num2 = dp_min[1];
        num3 = dp_min[2];
        dp_min[0] = min(num1 , num2) + input1;
        dp_min[1] = min({ num1, num2 , num3 }) + input2;
        dp_min[2] = min(num2, num3) + input3;
    }
    
    cout << *max_element(dp_max.begin(), dp_max.end()) <<" " << *min_element(dp_min.begin(), dp_min.end());
    return 0;
}