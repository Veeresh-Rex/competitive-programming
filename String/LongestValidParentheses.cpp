/*
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
 
 
 #include <bits/stdc++.h>
using namespace std;
int solve(string s)
{
    int left = 0;
    int right = 0;
    int i = 0;
    int maxLen = INT_MIN;
    while (s[i])
    {
        if (s[i] == '(')
            left++;
        else
            right++;
        if (left == right)
            maxLen = max(maxLen, left * 2);
        i++;
    }
    left = right = 0;
    i = s.size() - 1;
    while (s[i])
    {
        if (s[i] == '(')
            left++;
        else
            right++;
        if (left == right)
        {
            maxLen = max(maxLen, left * 2);
        }
        if (left > right)
        {
            left = right = 0;
        }
        i--;
    }

    return maxLen;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int x = solve(s);
        cout << x << "\n";
    }

    return 0;
}
