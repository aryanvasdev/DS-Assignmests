class Solution {
    vector<int> s;
    vector<int> Min_s;
  public:
    Solution() {
        s.clear();
        Min_s.clear();
        
    }

   
    void push(int x)
    {
        s.push_back(x);
        
        if(Min_s.empty() || x <= Min_s.back())
        {
            Min_s.push_back(x);
        }
    }

   
    void pop() 
    {
        if(!s.empty())
        {
            if(Min_s.back() == s.back())
            {
                Min_s.pop_back();
            }
            s.pop_back();
        }
    }

        
   
    int peek() 
    {
       if(s.empty())
       {
           return -1;
       }
       else
       {
           return s.back();
       }
    }
        

  
    int getMin() 
    {
        if(Min_s.empty())
        {
            return -1;
        }
        else
        {
            return Min_s.back();
        }
    }
};