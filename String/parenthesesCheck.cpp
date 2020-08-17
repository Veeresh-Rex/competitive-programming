#include <bits/stdc++.h>
using namespace std;
#define Endl "\n"
bool solve(string st)
{
    stack<char> s;
    char x;
    int i = 0;
    while (st[i])
    {
        x = st[i];
        if (x == '{' || x == '[' || x == '(')
            s.push(x);

        else
        {
            if (s.empty())
                return 0;
            switch (x)
            {
            case '}':
                if (s.top() == '{')
                    s.pop();
                else
                {
                    return 0;
                }

                break;
            case ')':
                if (s.top() == '(')
                    s.pop();
                else
                {
                    return 0;
                }
                break;
            case ']':
                if (s.top() == '[')
                    s.pop();
                else
                {
                    return 0;
                }
                break;
            default:
                break;
            }
        }

        i++;
    }
    if (s.empty())
        return true;
    else
        return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (solve(s))
            cout << "balanced" << Endl;
        else
            cout << "not balanced" << Endl;
    }

    return 0;
}
