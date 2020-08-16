// https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1/?track=amazon-arrays&batchId=192

#include<bits/stdc++.h>
using namespace std;
int max_sum(int A[],int N);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N; i++)
        {
            cin>>A[i];
        }
        cout<<max_sum(A,N)<<endl;
    }
}
int max_sum(int A[],int N)
{
    int Sum = A[0];
    int res, Max_sum=0;
    for(int i=1;i<N;i++)
    {
        Sum += A[i];
        Max_sum += A[i]*i;
    }
    res = Max_sum;
    int sumofZero = Max_sum;
    for(int i = 1;i<N;i++)
    {
        Max_sum = Max_sum -(Sum-A[i-1]) + (N-1)*A[i-1];
        res = max(Max_sum,res);
    }
    return res;
}