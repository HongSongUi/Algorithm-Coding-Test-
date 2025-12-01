#include <bits/stdc++.h>

using namespace std;
struct FileName
{
	string header;
	int number; 
	string origin;
	int idx;
};

bool Cmp(FileName a, FileName b)
{
	string h1 = a.header, h2 = b.header;
	transform(h1.begin(), h1.end(), h1.begin(), ::tolower);
	transform(h2.begin(), h2.end(), h2.begin(), ::tolower);

	if (h1 != h2) return h1 < h2;
	if (a.number != b.number) return a.number < b.number;
	return a.idx < b.idx; // 입력 순서 유지
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
		name.idx = i;
		vec.emplace_back(name);
	}
	sort(vec.begin(), vec.end(), Cmp);
	for (int i = 0; i < vec.size(); i++)
	{
		answer.emplace_back(vec[i].origin);
	}
    return answer;
}