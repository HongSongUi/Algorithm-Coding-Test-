#include <string>
#include <vector>

using namespace std;


vector<int> solution(int n, int s) {
	vector<int> answer;
    int base = s / n;
	int remain = s % n;

	if (base == 0)
	{
		answer.emplace_back(-1);
		return answer;
	}
    for (int i = 0; i < n; i++) 
    {
        if (i < n - remain) answer.push_back(base);
        else answer.push_back(base + 1);
    }
    return answer;
}