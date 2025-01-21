#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input, target;
    cin >> input >> target;

    stack<char> s;

    string temp = "";
    for (auto ch : input)
    {
        s.push(ch);

        if (s.size() >= target.length())
        {
            temp = "";
            for (int i = 0; i < target.length(); i++)
            {
                temp = s.top() + temp;
                s.pop();
            }
            if (temp != target)
            {
                for (int i = 0; i <temp.length(); i++)
                {
                    s.push(temp[i]);
                }
                
            }
        }
    }
    string answer = "";

    while (!s.empty())
    {
        answer += s.top();
        s.pop();
    }
    if (answer == "")
    {
        cout << "FRULA";
    }
    else
    {
        reverse(answer.begin(), answer.end());
       cout << answer;
    }
    return 0;
}