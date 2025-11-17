#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	
	for (int i = 0; i < prices.size(); i++)
	{
		int num = prices[i];
		int sec = 0;
		for (int j = i+1; j < prices.size(); j++)
		{
			sec++;
			if (num > prices[j])
			{
				break;
			}
		}
		answer[i] = sec;
	}
	
    return answer;
}