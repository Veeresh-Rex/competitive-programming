#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
void solve(vector<int> arr)
{
    int n = arr.size();
    int mid;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    maxHeap.push(arr[0]);
    // if (arr[0] > arr[1])
    // {

    //     minHeap.push(arr[1]);
    // }
    // else
    // {
    //     maxHeap.push(arr[1]);
    //     minHeap.push(arr[0]);
    // }
    mid = arr[0];
    cout << mid << "\n";
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        if (maxHeap.size() == minHeap.size())
        {
            if (x < mid)
            {
                maxHeap.push(x);
                mid = maxHeap.top();
            }

            else
            {
                minHeap.push(x);
                mid = minHeap.top();
            }
        }
        else
        {
            if (maxHeap.size() > minHeap.size())
            {
                if (arr[i] < mid)
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(x);
                }
                else
                {
                    minHeap.push(arr[i]);
                }
                mid = (minHeap.top() + maxHeap.top()) / 2;
            }

            else
            {
                if (x > mid)
                {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(x);
                }
                else
                {
                    maxHeap.push(x);
                }
                mid = (minHeap.top() + maxHeap.top()) / 2;
            }
        }
        cout << mid << "\n";
    }
}
int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    // int sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr);
    return 0;
}
