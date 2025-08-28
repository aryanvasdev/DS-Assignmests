vector<int> Solution::prevSmaller(vector<int> &A)
{
    int n = A.size();
    vector<int> val(n,-1);
    stack<int> s;
    
    for(int i = 0; i < n ; i++)
    {
        while(!s.empty() && (A[i] <= A[s.top()]))
        {
            s.pop();
        }
        if(!s.empty())
        {
            val[i] = A[s.top()];
        }
        s.push(i);
    }
    return val;
}
