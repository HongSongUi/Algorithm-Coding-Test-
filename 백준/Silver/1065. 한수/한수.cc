#include <iostream>

using namespace std;

int check(int num) {
	int cnt = 0;
	int one = 0;
	int ten = 0;
	int hun = 0;
	if (num < 100) {
		cnt++;
	}
	else {
		
		hun = num / 100;
		ten = (num % 100) / 10;
		one = (num % 100) % 10;
		if ((hun - ten) == (ten - one)) {
			cnt++;
		}
	}
	return cnt;

}
int main() {
	int lim;
	int count = 0;
	cin >> lim;
	for (int i = 1; i <= lim; i++) {
		count += check(i);
	}
	cout << count;
	return 0;
}