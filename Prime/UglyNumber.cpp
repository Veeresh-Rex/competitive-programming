/* Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. Write a program to find Nth Ugly Number.

Example 1:

Input:
N = 10
Output: 12
Explanation: 10th ugly number is 12.

Example 2:

Input:
N = 4
Output: 4
Explanation: 4th ugly number is 4.
*/

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    
	     ull ugly[n];
    ugly[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    ull next_multiple_of_2 = 2;

    ull next_multiple_of_3 = 3;

    ull next_multiple_of_5 = 5;

    ull next_ugly_no = 1;
    for (int i = 1; i < n; i++)
    {
       next_ugly_no = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2)
        {
            i2 = i2 + 1;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if (next_ugly_no == next_multiple_of_3)
        {
            i3 = i3 + 1;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if (next_ugly_no == next_multiple_of_5)
        {
            i5 = i5 + 1;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }
    return next_ugly_no;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
