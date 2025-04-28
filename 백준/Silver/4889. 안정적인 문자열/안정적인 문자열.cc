#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "";
    int test = 1;
    while (true)
    {
        cin >> s;
        int count = 0;
        stack<char> st;
        if (s.find('-') != string::npos)
        {
            break;
        }
        for (int i = 0; i < s.length(); i ++)
        {
            char ch = s[i];
            if (st.empty())
            {
                st.push(ch);
            }
            else
            {
                if (st.top() == '{' && ch == '}')
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }
        while (!st.empty())
        {
            char ch = st.top();
            st.pop();
            if (ch == st.top())
            {
                
                count++;
            }
            else
            {
                count += 2;
            }
            st.pop();
        }
        cout << test << ". " << count << '\n';
        test++;
    }

    return 0;
}