#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a = "";
	string b = "";
	cin >> a >> b;

	int lenA = a.length();
	int lenB = b.length();

	int lcm = (lenA * lenB) / gcd(lenA, lenB);
	string tmpA = "";
	string tmpB = "";
	while (tmpA.length() < lcm) tmpA += a;
	while (tmpB.length() < lcm) tmpB += b;

	cout << (tmpA == tmpB);
	return 0;
}