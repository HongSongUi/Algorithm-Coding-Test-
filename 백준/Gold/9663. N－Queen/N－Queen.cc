#include <bits/stdc++.h>
using namespace std;
int n;

bool isVaild(int num , vector<int>& temp)
{
    for (int i = 0; i < num; i++)
    {
        if (temp[i] == temp[num] || abs(temp[num] - temp[i]) == num - i)
        {
            return false;
        }
    }
    return true;
}

void Queen(int count,int& answer, vector<int>& temp)
{
    if (count == n)
    {
        answer++;
    }
    else
    {
        for (int i = 0; i < temp.size(); i++)
        {
            temp[count] = i;
            if (isVaild(count, temp))
            {
                Queen(count + 1, answer, temp);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<int> temp(n);
    int answer = 0;
    Queen(0, answer, temp);
    cout << answer;
    
    return 0;
}