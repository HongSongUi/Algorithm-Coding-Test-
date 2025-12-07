#include <string>
#include <vector>

using namespace std;
int one = 0;
int zero = 0;

void QuadTree(int l, int t, int r, int b, vector<vector<int>> & vec)
{
	int w = r - l;
	if (w == 1)
	{
		if (vec[t][l] == 1)
		{
			one++;
		}
		else
		{
			zero++;
		}
		return;
	}
	int num = vec[t][l];
	bool isFind = true;
	for (int i = t; i < b; i++)
	{
		for (int j = l; j < r; j++)
		{
			if (num != vec[i][j])
			{
				isFind = false;
				break;
			}
		}
		if (!isFind) break;
	}
	if (isFind)
	{
		if (num == 1)
		{
			one++;
		}
		else if (num == 0)
		{
			zero++;
		}
		return;
	}
	int r1 = l + w / 2;
	int b1 = t + w / 2;
	QuadTree(l, t, r1, b1, vec);
	QuadTree(r1, t, r,b1, vec);
	QuadTree(l, b1, r1, b, vec);
	QuadTree(r1, b1, r, b, vec);
	return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int left = 0;
	int top = 0;
	int right = arr[0].size();
	int btm = arr.size();
	QuadTree(left, top, right, btm, arr);
	answer.emplace_back(zero);
	answer.emplace_back(one);
    return answer;
}