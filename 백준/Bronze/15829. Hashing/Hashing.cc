#include <iostream>
using namespace std;

int main()
{
	int length = 0;
	long long m = 1234567891;
	string temp = "";
	cin >> length;
	cin >> temp;
	int num = 0;
	long long r = 1;
		long long hash = 0;
	for (int i = 0; i < length; i++)
	{
		num = temp[i] - 96; 
		hash = (hash + (num * r)) % m;
		r = (r * 31) % m;
	}
	cout << hash;
}	