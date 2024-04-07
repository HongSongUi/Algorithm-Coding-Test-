#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int half = 0;
	string temp = "";
	int index = 0;
	int rindex = 0;
	int count = 0;
	while (true)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		temp = to_string(n);
		rindex = temp.length() - 1;
		half = temp.length() / 2;
		if (half % 2 != 0)
		{
			half++;
		}
		while (index < half)
		{
			if (temp[index] != temp[rindex])
			{
				cout << "no" << endl;
				break;
			}
			else
			{
				count++;
			}
			index++;
			rindex--;
		}
		if (count == half)
		{
			cout << "yes"<<endl;
		}
		count = 0;
		index = 0;
	}
	return 0;
}	
