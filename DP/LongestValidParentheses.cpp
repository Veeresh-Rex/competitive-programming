/* Input : ((()
Output : 2
Explanation : ()

Input: )()())
Output : 4
Explanation: ()() 

Input:  ()(()))))
Output: 6
Explanation:  ()(())
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
int longestparenthesisn(string s)
{
    stack<int> st;
    st.push(-1);
    int len = INT_MIN;
    int dif;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
            continue;
        }
        int x = st.top();
        if (st.top() == -1)
            continue;
        switch (s[i])
        {
        case ')':
            dif = i - st.top() + 1;
            len = max(len, dif);
            st.pop();
            break;

        default:
            break;
        }
    }
    return len;
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
        string para;
        cin >> para;
        cout << longestparenthesisn(para) << "\n";
    }
    return 0;
}
