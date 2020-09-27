/* 3
2
3
4*/




#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll arr[n];
    vector<pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        //  cout << arr[i] << "\n";
        mp.push_back(make_pair(arr[i], -1L));
    }
    sort(arr, arr + n);
    ll t = arr[n - 1];
    // cout << t << "\n";
    ll x = 1;
    ll path = 0;
    ll maxPath = INT_MIN;
    int j = 0;
    while (arr[j] == 0)
    {
        // auto it = mp.begin();
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->first == arr[j])
            {
                it->second = maxPath;
            }
        }

        j++;
    }

    while (x != t + 1)
    {

        if (x & 1)
        {
            path += 2;
            maxPath = max(maxPath, path);
            if (x == arr[j])
            {
                for (auto it = mp.begin(); it != mp.end(); it++)
                {
                    if (it->first == arr[j])
                    {
                        it->second = maxPath;
                    }
                }
                j++;
            }
        }
        else
        {
            path -= 1;
            // cout << "Test\n";
            maxPath = max(maxPath, path);

            if (x == arr[j])
            {
                for (auto it = mp.begin(); it != mp.end(); it++)
                {
                    if (it->first == arr[j])
                    {
                        it->second = maxPath;
                    }
                }
                j++;
            }
        }
        x++;
    }
    for (auto i : mp)
    {
        if (i.second == INT_MIN)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << i.second << "\n";
        }
    }

    return 0;
}
