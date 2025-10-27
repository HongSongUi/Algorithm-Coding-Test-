#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) 
{
    
   unordered_map<string, bool> hash;

    for (int i = 0; i< phone_book.size(); i++)
    {
        hash[phone_book[i]] = true;
    }

    bool answer = true;

    for (int i = 0; i < phone_book.size(); i++)
    {
        string target = phone_book[i];
        for (int j = 0; j < target.size() - 1; j++)
        {
            if (hash[target.substr(0, j + 1)])
            {
                answer = false;
                return answer;
            }
        }
    }
    return answer;
}