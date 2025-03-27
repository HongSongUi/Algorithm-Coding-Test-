#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    
    double r1, r2, b1, b2, y1, y2;
    cin >> r1 >> r2 >> b1 >> b2 >> y1 >> y2;

    // 빨간색 점 정렬
    if (r1 > r2) {
        swap(r1, r2);
    }
    // 파란색 점 정렬
    if (b1 > b2) {
        swap(b1, b2);
    }
    // 노란색 점 정렬
    if (y1 > y2) {
        swap(y1, y2);
    }

    double len = n;

    // 빨간색 접기
    if (r1 != r2) {
        double fold = (r1 + r2) / 2.0;
        double remain = len - fold;
        len = max(fold, remain);

        b1 = (b1 < fold) ? 2 * fold - b1 : b1;
        b2 = (b2 < fold) ? 2 * fold - b2 : b2;
        y1 = (y1 < fold) ? 2 * fold - y1 : y1;
        y2 = (y2 < fold) ? 2 * fold - y2 : y2;

        b1 -= fold;
        b2 -= fold;
        y1 -= fold;
        y2 -= fold;

        b1 = abs(b1);
        b2 = abs(b2);
        y1 = abs(y1);
        y2 = abs(y2);

        if (b1 > b2) swap(b1, b2);
        if (y1 > y2) swap(y1, y2);
    }

    // 파란색 접기
    if (b1 != b2) {
        double fold = (b1 + b2) / 2.0;
        double remain = len - fold;
        len = max(fold, remain);

        y1 = (y1 < fold) ? 2 * fold - y1 : y1;
        y2 = (y2 < fold) ? 2 * fold - y2 : y2;

        y1 -= fold;
        y2 -= fold;

        y1 = abs(y1);
        y2 = abs(y2);

        if (y1 > y2) swap(y1, y2);
    }

    // 노란색 접기
    if (y1 != y2) {
        double fold = (y1 + y2) / 2.0;
        double remain = len - fold;
        len = max(fold, remain);
    }

    // 결과 출력
    cout << fixed << setprecision(1) << len << endl;
    return 0;
}
