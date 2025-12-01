#include <bits/stdc++.h>

using namespace std;
struct FileName
{
	string header;
	int number; 
	string origin;

};

bool Cmp(FileName a, FileName b)
{
	transform(a.header.begin(), a.header.end(), a.header.begin(), ::tolower);
	transform(b.header.begin(), b.header.end(), b.header.begin(), ::tolower); 
	if (a.header == b.header) 
	{
		return a.number < b.number;
	} 
	int result = a.header.compare(b.header);
	return result < 0;
}


vector<string> solution(vector<string> files) {
    vector<string> answer;
   vector<FileName> vec;
	for (int i = 0; i < files.size(); i++)
	{
		string tmp = files[i];
		string h = "";
		string num = "";
		FileName name;
		int idx = 0;
		while (!isdigit(tmp[idx]))
		{
			h += tmp[idx];
			idx++;
		}
		while (isdigit(tmp[idx])&& num.length()<5)
		{
			num += tmp[idx];
			idx++;
		}
		name.header = h;
		name.number = stoi(num);
		name.origin = tmp;
		vec.emplace_back(name);
	}
	stable_sort(vec.begin(), vec.end(), Cmp);
	for (int i = 0; i < vec.size(); i++)
	{
		answer.emplace_back(vec[i].origin);
	}
    return answer;
}