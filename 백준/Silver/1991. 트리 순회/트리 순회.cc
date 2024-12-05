#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, pair<string, string>> tree;

void PreOrder(string node) 
{
    if (node == ".")
    {
        return;
    }
    cout << node;                            
    PreOrder(tree[node].first);              
    PreOrder(tree[node].second);             
}

void InOrder(string node)
{
    if (node == ".")
    {
        return;
    }
    InOrder(tree[node].first);               
    cout << node;                            
    InOrder(tree[node].second);              
}

void PostOrder(string node) 
{
    if (node == ".")
    {
        return;
    }
    PostOrder(tree[node].first);             
    PostOrder(tree[node].second);            
    cout << node;                            
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string name, left, right;
    for (int i = 0; i < n; i++) 
    {
        cin >> name >> left >> right;
        tree[name] = { left, right };
    }

    PreOrder("A");
    cout << '\n';
    InOrder("A");
    cout << '\n';
    PostOrder("A");
    cout << '\n';

    return 0;
}