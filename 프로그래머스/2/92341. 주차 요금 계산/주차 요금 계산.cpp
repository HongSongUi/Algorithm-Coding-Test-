#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    	map<string, vector<int>> data;

	for (int i = 0; i < records.size(); i++)
	{
		string r = records[i];
		string tmp = r.substr(0,5);
		int t = (stoi(tmp.substr(0, 2)) * 60) + (stoi(tmp.substr(3, 2)));
		string n = r.substr(6, 4);
		data[n].emplace_back(t);
	}
	for (auto val : data)
	{
		if (val.second.size() % 2 != 0)
		{
			data[val.first].emplace_back(1439);
		}
	}

	int totalTime = 0;
	int totalMoney = 0;
	for (auto val : data)
	{
		totalTime = 0;
		totalMoney = 0;
		for (int i = 0; i < val.second.size(); i += 2)
		{
			int InTime = val.second[i];
			int OutTime = val.second[i + 1];
			totalTime += (OutTime - InTime);
		}
		if (totalTime > fees[0])
		{
			totalMoney += fees[1];
			int tmp = totalTime - fees[0];
			int m = ceilf((float)tmp / (float)fees[2])* fees[3];
			
			totalMoney += m;
		}
		else
		{
			totalMoney = fees[1];
		}
		answer.emplace_back(totalMoney);
	}
    return answer;
}