#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], i;
        int pos = 0;
        int flag = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1 && flag == 0)
            {
                pos = i;
                flag = 1;
            }
        }
        int start = pos;
        flag = 1;
        for (i = pos + 1; i < n; i++)
        {
            if (a[i] == 1)
            {
                if (i - start < 6)
                {
                    flag = 0;
                    break;
                }
                start = i;
            }
        }
        if (flag == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
