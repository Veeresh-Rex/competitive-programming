/*  INPUT -> 1
             abc
     OUTPUT-> a b c ab bc abc
     
     */

#include <bits/stdc++.h>
using namespace std;
void solve(string s, string ans, int index)
{
    index++;
    if (index == s.size())
    {
        cout << ans << " ";
        return;
    }
    solve(s, ans + s[index], index);
    solve(s, ans, index);
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
        string s;
        cin >> s;
        string ans = "";
        int index = -1;
        solve(s, ans, index);
    }
    return 0;
}
