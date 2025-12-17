#include <string>
#include <vector>

using namespace std;
int gcd(int a, int b)
{
	int tmp = 0;
	while (b > 0)
	{
		tmp = a;
		a = b;
		b = tmp % a;
	}
	return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
	int gcdA = arrayA[0];
	int gcdB = arrayB[0];

	for (int i = 0; i < arrayA.size(); i++)
	{
		gcdA = gcd(gcdA, arrayA[i]);
		gcdB = gcd(gcdB, arrayB[i]);
	}
	int max_value = 0;
	bool flagA = false;
	bool flagB = false;
	for (int i = 0; i < arrayA.size(); i++)
	{
		if (arrayA[i] % gcdB == 0)
		{
			flagA = true;
			break;
		}
	}
	for (int i = 0; i < arrayB.size(); i++)
	{
		if (arrayB[i] % gcdA == 0)
		{
			flagB = true;
			break;
		}
	}
	if (flagA && !flagB)
	{
		answer = gcdA;
	}
	else if (!flagA && flagB)
	{
		answer = gcdB;
	}
	else if(!flagA && !flagB)
	{
		answer = max(gcdA, gcdB);
	}
	else
	{
		answer = 0;
	}
    return answer;
}