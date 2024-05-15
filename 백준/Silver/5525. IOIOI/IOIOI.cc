#include <bits/stdc++.h>
using namespace std;

void KMPSearch(const string& pat, const string& txt) {
	int M = pat.length();
	int N = txt.length();

	// 패턴의 접두사와 접미사가 일치하는 최대 길이를 저장하는 lps 배열 계산
	vector<int> lps(M, 0);
	int len = 0; // 이전까지 일치한 문자의 개수
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len != 0) {
				len = lps[len - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}

	int count = 0; // 패턴이 발견된 횟수

	int j = 0; // 패턴 인덱스
	for (int i = 0; i < N;) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			// 패턴을 찾았을 때
			count++;
			j = lps[j - 1];
		}
		else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}

	cout << count;
}

int main() {
	string buff = "";
	int n = 0;
	int m = 0;
	cin >> n >> m;

	int num = (n * 2) + 1;
	for (int i = 0; i < num; i++) {
		if (i % 2 == 0) {
			buff += "I";
		}
		else {
			buff += "O";
		}
	}

	string temp;
	cin >> temp;

	KMPSearch(buff, temp);

	return 0;
}