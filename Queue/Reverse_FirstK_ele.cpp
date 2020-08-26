/*   Input:
N = 5, K = 3
Queue = 1 2 3 4 5
Output: 3 2 1 4 5
Explanation: After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.


*/


queue<ll> modifyQueue(queue<ll> q, int k)
{
    //add code here.
    
    stack<ll>st;
    for(int i=0;i<k;i++)
    {
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<k;i++)
    {
        q.push(st.top());
        st.pop();
    }
    for(int i=0;i<q.size()-k;i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}
