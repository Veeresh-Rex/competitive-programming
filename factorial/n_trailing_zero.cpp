/*  



https://practice.geeksforgeeks.org/problems/n-trailing-zeroes-in-factorials/0



Given an integer n, we need to find the number of positive integers whose factorial ends with n zeros.

Input:

The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows, a single line of the input containing a positive integer N.
Output:

For each testcase, Print the count of positive numbers whose factorial ends with n zeros.
Constraints:

1<=T<=100

1<=N<=1000
Example:

Input:

2

1

5

Output:

5

0

Explanation:

Testcase 1: Here, 5! = 120, 6! = 720,
7! = 5040, 8! = 40320 and 9! = 362880.

Testcase 2: No such number exists.


*/


#include <bits/stdc++.h>
using namespace std;
int traling(int n)
{
     int ans = 0;
    int i = 5;
    while (1)
    {
        if (n / (i) == 0)
        {
            break;
        }
        ans += n / (i);
        i *= 5;
    }
    return ans;
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        int count=0;
        for (int i = 5; i <= num*5+5; i ++)
        {
            if (traling(i) == num)
            {
               count++;
            }
        }
      cout<<count<<"\n";
       
    }
    return 0;
}
