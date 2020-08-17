#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2)
{

    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    vector<int> result(len1 + len2, 0);

    int n1 = 0, m1 = 0;
    for (int i = len1 - 1; i >= 0; i--)
    {
        m1 = 0;
        int val1 = num1[i] - '0';
        int carry = 0;
        int sum = 0;
        for (int j = len2 - 1; j >= 0; j--)
        {
            int val2 = num2[j] - '0';
            sum = val1 * val2 + result[n1 + m1] + carry;
            carry = sum / 10;
            sum %= 10;
            result[n1 + m1] = sum;
            m1++;
        }
        if (carry > 0)
        {
            result[n1 + m1] += carry;
        }
        n1++;
    }
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
    {
        i--;
    }
    if (i == -1)
        return "0";
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
    return s;
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
        int n;
        cin >> n;
        string s = "1";
        for (int i = 2; i <= n; i++)
            s = multiply(s, to_string(i));
        cout << s << endl;
    }
    return 0;
}
