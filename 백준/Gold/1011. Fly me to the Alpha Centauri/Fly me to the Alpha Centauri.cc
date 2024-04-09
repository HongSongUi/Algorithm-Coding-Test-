#include <iostream>
#include<math.h> 
using namespace std;

int main() {
	int T = 0;
	float x = 0;
	float y = 0;
	float temp = 0;
	float out = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		temp = (int)sqrt(y - x);
		if ((y - x) == temp * temp) {
			out = (2 * temp) - 1;
		}
		else if (temp * temp < (y - x) && (y - x) <= (temp * temp) + temp) {
			out= 2 * temp;
		}
		else if ((temp * temp) + temp < (y - x) && (y - x) <= (temp + 1) * (temp + 1)) {
			out = (2 * temp) + 1;
		}
		cout << out << '\n';
	}
}