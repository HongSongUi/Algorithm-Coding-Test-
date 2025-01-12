#include <bits/stdc++.h>
using namespace std;

int Conversion(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input = "";
    cin >> input;
    stack<char> buff;
    string answer = "";
    char ch;
    for (int i = 0; i < input.length(); i++)
    {
        ch = input[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            answer += ch;
        }
        else if (buff.empty() || ch == '(')
        {
            buff.push(ch);
        }
        else if (ch == ')')
        {
            while (buff.top() != '(')
            {
                answer += buff.top();
                buff.pop();
            }
            buff.pop();
        }
        else if (Conversion(buff.top()) < Conversion(ch))
        {
            buff.push(ch);
        }
        else
        {
            while (!buff.empty())
            {
                if (Conversion(buff.top()) < Conversion(ch))
                {
                    break;
                }
                answer += buff.top();
                buff.pop();
            }
            buff.push(ch);
        }
    }
    while (!buff.empty())
    {
        answer += buff.top();
        buff.pop();
    }
    cout << answer << '\n';
    return 0;
}