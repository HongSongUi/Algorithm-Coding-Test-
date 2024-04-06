#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num = 0;
	int result = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		result += pow(num,2);
	}
	result %= 10;
	cout << result;
}