#include <bits/stdc++.h>
using namespace std;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string target = "";
    string s = "";

    getline(cin, target);
    getline(cin, s);
    int index = 0;
    int count = 0;
    while (target.find(s,index) != string::npos)
    {
        index = target.find(s, index) + s.length();
        count++;
    }
    cout << count;
    
    return 0;
}