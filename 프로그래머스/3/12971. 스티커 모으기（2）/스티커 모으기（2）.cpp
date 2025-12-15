#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;

	if (sticker.size() == 1)
	{
		answer = sticker[0];
        return answer;
	}
	else if (sticker.size() == 2)
	{
		answer = max(sticker[0], sticker[1]);
        return answer;
	}

	vector<int> dp1(sticker.size(), 0);
	vector<int> dp2(sticker.size(), 0);

	dp1[0] = sticker[0];
	dp1[1] = dp1[0];

	for (int i = 2; i < sticker.size() - 1; i++)
	{
		dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
	}
	
	dp2[0] = 0;
	dp2[1] = sticker[1];
	for (int i = 2; i < sticker.size(); i++)
	{
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
	}
	answer = max(dp1[sticker.size() - 2], dp2[sticker.size()-1]);

    return answer;
}