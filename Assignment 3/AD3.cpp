class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> val(n,-1);
        stack<int> s;
        
        for(int i = 0 ;i < n ; i++)
        {
            while(!s.empty() && (arr[i] > arr[s.top()]))
            {
                int index = s.top();
                s.pop();
                val[index] = arr[i];
            }
            s.push(i);
        }
        return val;
    }
};