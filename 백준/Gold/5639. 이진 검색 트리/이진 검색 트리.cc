#include <bits/stdc++.h>
using namespace std;

void PostOrder(const vector<int>& preorder, int& index, int min_val, int max_val) 
{
    if (index >= preorder.size())
    {
        return;
    }

    int root_val = preorder[index];


    if (root_val < min_val || root_val > max_val)
    {
        return;
    }
    index++;
    PostOrder(preorder, index, min_val, root_val);
    PostOrder(preorder, index, root_val, max_val);
    cout << root_val << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> preorder;
    int num;

    while (cin >> num) {
        preorder.push_back(num);
    }

    int index = 0;
    PostOrder(preorder, index, -1, 1000000);

    return 0;
}