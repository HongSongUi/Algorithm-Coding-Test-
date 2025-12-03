#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{	
    int answer = 0;
	int curr_pos = 1;
	int dist = w * 2 + 1;

	for (int i = 0; i < stations.size(); i++)
	{
		int p = stations[i];
		int left = p - w - 1;
		int right = p + w + 1;
		
		if (curr_pos <= left)
		{
			int non_coverd = left - curr_pos + 1;

			answer += (non_coverd + dist - 1) / dist;
		}
		curr_pos = right;
	}
	if (curr_pos <= n)
	{
		int non_coverd = n - curr_pos + 1;

		answer += (non_coverd + dist - 1) / dist;
	}
    return answer;
}