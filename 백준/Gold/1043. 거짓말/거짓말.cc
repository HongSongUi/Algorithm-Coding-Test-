#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find_root(int x) {
    if (parent[x] != x) {
        parent[x] = find_root(parent[x]);
    }
    return parent[x];
}

void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int t;
    cin >> t;
    vector<int> truth;
    for (int i = 0; i < t; i++) {
        int person;
        cin >> person;
        truth.push_back(person);
    }


    vector<vector<int>> parties(m);
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        parties[i].resize(num);
        for (int j = 0; j < num; j++) {
            cin >> parties[i][j];
        }

    
        for (int j = 1; j < num; j++) {
            union_root(parties[i][0], parties[i][j]);
        }
    }

 
    int truth_root = truth.empty() ? -1 : find_root(truth[0]);
    for (int person : truth) {
        union_root(truth_root, person);
    }

    int answer = 0;
    for (const auto& party : parties) {
        bool canLie = true;
        for (int person : party) {
            if (find_root(person) == truth_root) {
                canLie = false;
                break;
            }
        }
        if (canLie) {
            answer++;
        }
    }

    cout << answer << endl;
    return 0;
}