#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define N 105

class myComparator
{
public:
    int operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
    {
        return a.first > b.first;
    }
};

int *solve(int arr[][N], int k)
{

    int *a = new int[k * k];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, myComparator> minHeap;

    for (int i = 0; i < k; i++)
    {
        pair<int, pair<int, int>> s = make_pair(arr[i][0], make_pair(i, 0));
        minHeap.push(make_pair(arr[i][0], make_pair(i, 0)));
        cout << s.first << " :: " << s.second.first << " :: " << s.second.second << " \n";
    }
    int i = 0;
    while (!minHeap.empty())
    {
        auto p = minHeap.top();
        cout << p.first << " : " << p.second.first << " : " << p.second.second << "\n";
        minHeap.pop();

        a[i] = p.first;
        if (p.second.second < k)
        {
            auto s = p.second.second;
            minHeap.push(make_pair(arr[p.second.first][s + 1], make_pair(p.second.first, p.second.second + 1)));
            i++;
        }
    }
    for (int i = 0; i < k * k; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        int arr[N][N];
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        int *output = solve(arr, k);
        // for (int i = 0; i < k * k; i++)
        // {
        //     cout << output[i] << " ";
        // }
    }

    return 0;
}
