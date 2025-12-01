#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> nicknames;
	queue<pair<int, string>> q;
	for (int i = 0; i < record.size(); i++)
	{
		string r = record[i];
		string order = "";
		string uid = "";
		string name = "";
		stringstream ss(r);
		ss >> order >> uid >> name;
		if (order == "Enter")
		{	
			nicknames[uid] = name;
			q.push(make_pair(0, uid));
		}
		else if (order == "Leave")
		{
			q.push(make_pair(1, uid));
		}
		else if (order == "Change")
		{
			nicknames[uid] = name;
		}
	}
	while (!q.empty())
	{
		int order = q.front().first;
		string id = q.front().second;
		string tmp = nicknames[id];;
		if (order == 0)
		{
			tmp += "님이 들어왔습니다.";
		}
		else
		{
			tmp += "님이 나갔습니다.";
		}
		answer.emplace_back(tmp);
		q.pop();
	}
    return answer;
}