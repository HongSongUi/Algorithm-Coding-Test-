#include <iostream>
using namespace std;

int main()
{
	int a, b, c = 0;
	while (true)
	{
		cin >> a >> b >> c;
		if ((a == 0) && (b == 0) && (c == 0))
		{
			break;
		}
		a *= a;
		b *= b;
		c *= c;
		if (((a + b) == c) || ((a+c)==b) || ((b+c)==a))
		{
			cout << "right"<<endl;
		}
		else
		{
			cout << "wrong" << endl;
		}
	}
}