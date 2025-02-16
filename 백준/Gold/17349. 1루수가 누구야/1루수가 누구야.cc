#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> statements(9);

    for (int i = 0; i < 9; i++) 
    {
        cin >> statements[i].first >> statements[i].second;
    }
    int answer = -1; 
    for (int candidate = 1; candidate < 10; candidate++) 
    {
        int lie_count = 0;

        for (int i = 0; i < 9; i++) 
        {
            bool is_truth = statements[i].first;
            int target = statements[i].second;

            if (is_truth && target != candidate) 
            { 
                lie_count++;
            }
            if (!is_truth && target == candidate) 
            { 
                lie_count++;
            }
        }

        if (lie_count == 1) 
        { 
            if (answer == -1)
            {
                answer = candidate;
            }
            else 
            { 
                cout << -1;
                return 0;
            }
        }
    }

    cout << answer;
    return 0;
}