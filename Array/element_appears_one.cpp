#include <iostream>
using namespace std;

int elementAppearingOnce(int arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        res ^= arr[i];
    }

    return res;
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
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        cout << elementAppearingOnce(arr, N) << endl;
    }
    return 0;
}
