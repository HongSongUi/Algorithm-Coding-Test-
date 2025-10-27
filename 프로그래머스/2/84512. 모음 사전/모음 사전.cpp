#include <bits/stdc++.h>
using namespace std;
int answer = 0;
vector<char> word = { 'A','E','I','O','U' };

bool Findword(string target, string tmp)
{

	if (tmp == target)
	{
		return true;
	}
	if (tmp.length() >= 6)
	{
		answer--;
		return false;
	}

	for (int i = 0; i < word.size(); i++)
	{
		tmp += word[i];
		answer++;
		if (Findword(target, tmp))
		{
			return true;
		}
		tmp.pop_back();
	}
	return false;
}

int solution(string word) {
    string t = "";
	Findword(word, t);
    return answer;
}