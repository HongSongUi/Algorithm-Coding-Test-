#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	int d = 0;
    cin >> n >> d;
    vector<int> digits(d);
    iota(digits.begin(), digits.end(), 0); 

    long long answer = -1;

    do {
        if (digits[0] == 0) continue; 

        long long val = 0;
        for (int i = 0; i < d; ++i) 
        {
            val = val * d + digits[i];
        }

        if (val > n) 
        {
            if (answer == -1 || val < answer) 
            {
                answer = val;
            }
        }

    } while (next_permutation(digits.begin(), digits.end()));

    cout << answer << "\n";
	return 0;
}