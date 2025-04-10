#include <bits/stdc++.h>
using namespace std;

vector<int> sorted;
int n = 0, k = 0;
int answer = -1;
int save = 0;
void Merge(vector<int>& arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int t = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            sorted[t++] = arr[i++];
        }
        else
        {
            sorted[t++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        sorted[t++] = arr[i++];
    }
    while (j <= right)
    {
        sorted[t++] = arr[j++];
    }
    i = left;
    t = 0;
    while (i <= right)
    {
        arr[i++] = sorted[t++];
        save++;
        if (save == k)
        {
            answer = arr[i - 1];
        }
    }
}

void MergeSort(vector<int>& arr, int left , int right)
{
    int mid = 0;
    if (left < right)
    {
        mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> k;
    vector<int> arr(n);
    sorted.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MergeSort(arr, 0, n-1);
    cout << answer;
    return 0;
}