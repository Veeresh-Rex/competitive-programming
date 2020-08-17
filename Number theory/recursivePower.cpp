#include <bits/stdc++.h>
using namespace std;
static int stepCount = 0;
long long solve(int x, int y)
{
    if (y == 0)
    {
        stepCount++;
        return 1;
    }
    else
    {
        stepCount++;
        if (y % 2 == 0)
            return x * x * solve(x * x, (y / 2) - 1);
        else
        {
            return x * solve(x, y - 1);
        }
    }
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
    int x, y;
    cin >> x >> y;
    cout << solve(x, y) << endl;
    cout << "Steps : " << stepCount;
    return 0;
}
