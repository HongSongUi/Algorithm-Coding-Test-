#include <iostream>
#include <vector>
using namespace std;

int RePaint(vector<string>& vec, vector<string>& answer, int x_start, int y_start, int x_end, int y_end)
{
	int num = 0;
	int p = -1;
	int q = -1;
	for (int i = y_start; i < y_end; i++)
	{
		p++;
		for (int j = x_start; j < x_end; j++)
		{
			q++;
			if (vec[i][j] != answer[p][q])
			{
				num++;
			}
		}
		q = -1;
	}
	return num;
}

int main()
{
	int x, y = 0;
	cin >> y >> x;
	int min_value = 65;
	int num1 = x / 8;
	int num2 = y / 8;
	int limit_x = ((num1 - 1)*8) + (x % 8);
	int limit_y = ((num2 - 1) * 8) + (y % 8);
	int start_x = 0;
	int start_y = 0;
	int end_y = 0;
	int end_x = 0;
	vector<string> buff(y, "");
	vector<string> w_tile = { "WBWBWBWB",
							  "BWBWBWBW",
							  "WBWBWBWB",
							  "BWBWBWBW",
							  "WBWBWBWB",
							  "BWBWBWBW",
							  "WBWBWBWB",
							  "BWBWBWBW" };

	vector<string> b_tile = { "BWBWBWBW",
							  "WBWBWBWB",
							  "BWBWBWBW",
							  "WBWBWBWB",
							  "BWBWBWBW",
							  "WBWBWBWB",
							  "BWBWBWBW",
							  "WBWBWBWB" };
	for (int i = 0; i < y; i++)
	{
		cin >> buff[i];
	}

	for (int i = 0; i < limit_y+1; i++)
	{
		start_y = i;
		end_y = start_y + 8;
		for (int j = 0; j < limit_x+1; j++)
		{
			start_x = j;
			end_x = j + 8;
			int temp = min(RePaint(buff, b_tile, start_x, start_y, end_x, end_y), RePaint(buff, w_tile, start_x, start_y, end_x, end_y));
			if (min_value >= temp)
			{
				min_value = temp;
			}
		}
	}
	cout << min_value;
}