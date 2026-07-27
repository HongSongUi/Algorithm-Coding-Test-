#include <bits/stdc++.h>
using namespace std;
struct cmp
{
	bool operator()(const pair<string, int>& a, const pair<string, int>& b) const
	{
		   if (a.second == b.second)
            return a.first < b.first;

        return a.second > b.second;
	}
};
bool compare(pair<int, int>& a, pair<int, int>& b)
{
  if (a.first == b.first)
        return a.second < b.second;

    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {

	map<string, int> tmp;
	map<string, vector<pair<int,int>>> playes_map;
	set<pair<string, int>,cmp> genreSet;
	
	for (int i = 0; i < genres.size(); i++)
	{
		string genre = genres[i];
		int p = plays[i];
		tmp[genre] += p;
		playes_map[genre].emplace_back(make_pair(p,i));
	}
	for (auto& data : playes_map)
	{
		sort(data.second.begin(), data.second.end(), compare);
	}
	for (auto data : tmp)
	{
		genreSet.insert(make_pair(data.first, data.second));
	}
	vector<int> answer;
	for (auto data : genreSet)
	{
		string n = data.first;
	    if (playes_map[n].size() == 1)
	    {
		    answer.emplace_back(playes_map[n][0].second);
	    }
	    else
	    {
		    answer.emplace_back(playes_map[n][0].second);
		    answer.emplace_back(playes_map[n][1].second);
	    }
	}
    return answer;
}