#include <bits/stdc++.h>
using namespace std;
vector<bool> visited(100001, false);

bool CheckPoint(int point)
{
    if (point >= 0 && point <= 100000 && visited[point] == false)
    {
        return true;
    }
    return false;
}

int BFS(int start, int end)
{
    deque<pair<int, int>>q;
    q.push_back(make_pair(start, 0));
    visited[start] = true;
    while (!q.empty())
    {
        int cur_point = q.front().first;
        int cur_depth = q.front().second;
        q.pop_front();
        if (cur_point == end)
        {
            return cur_depth;
        }

        int fPoint = cur_point + 1;
        int bPoint = cur_point - 1;
        int dPoint = cur_point * 2;
        if (CheckPoint(dPoint))
        {
            q.push_front(make_pair(dPoint, cur_depth));
            visited[dPoint] = true;
        }
        if (CheckPoint(bPoint))
        {
            q.push_back(make_pair(bPoint, cur_depth + 1));
            visited[bPoint] = true;
        }
        if (CheckPoint(fPoint))
        {
            q.push_back(make_pair(fPoint, cur_depth + 1));
            visited[fPoint] = true;
        }
       
       
    }
    return 0;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start, target;
    cin >> start >> target;
   
    cout << BFS(start, target);
    return 0;
}