#include <bits/stdc++.h>
using namespace std;

int r, c, t;
vector<vector<int>> graph;
vector<pair<int, int>> air;
vector<int> dx = { -1, 0, 1, 0 };
vector<int> dy = { 0, -1, 0, 1 };

bool isValid(int x, int y) {
    return (x >= 0 && x < c) && (y >= 0 && y < r);
}

void Dust() {
    vector<vector<int>> temp(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (graph[i][j] > 0) {
                int count = 0;
                int spreadAmount = graph[i][j] / 5;

                for (int d = 0; d < 4; d++) {
                    int nx = j + dx[d];
                    int ny = i + dy[d];

                    if (isValid(nx, ny) && graph[ny][nx] != -1) {
                        temp[ny][nx] += spreadAmount;
                        count++;
                    }
                }

                graph[i][j] -= spreadAmount * count;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (graph[i][j] != -1)
                graph[i][j] += temp[i][j];
        }
    }
}

void Wind() {
    int top_y = air[0].second;
    int bt_y = air[1].second;

    for (int y = top_y - 1; y > 0; y--) graph[y][0] = graph[y - 1][0];
    for (int x = 0; x < c - 1; x++) graph[0][x] = graph[0][x + 1];
    for (int y = 0; y < top_y; y++) graph[y][c - 1] = graph[y + 1][c - 1];
    for (int x = c - 1; x > 1; x--) graph[top_y][x] = graph[top_y][x - 1];
    graph[top_y][1] = 0;


    for (int y = bt_y + 1; y < r - 1; y++) graph[y][0] = graph[y + 1][0];
    for (int x = 0; x < c - 1; x++) graph[r - 1][x] = graph[r - 1][x + 1];
    for (int y = r - 1; y > bt_y; y--) graph[y][c - 1] = graph[y - 1][c - 1];
    for (int x = c - 1; x > 1; x--) graph[bt_y][x] = graph[bt_y][x - 1];
    graph[bt_y][1] = 0;


    graph[top_y][0] = -1;
    graph[bt_y][0] = -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> t;
    graph.resize(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) {
                air.emplace_back(j, i);
            }
        }
    }

    for (int count = 0; count < t; count++) {
        Dust();
        Wind();
    }

    int answer = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (graph[i][j] > 0) answer += graph[i][j];
        }
    }

    cout << answer;
    return 0;
}