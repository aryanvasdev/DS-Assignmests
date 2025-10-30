bool checkSorted(queue<int>& q) {
        stack<int> s;
        int expected = 1; 
        int n = q.size(); 

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            if (front == expected) {
                expected++;
                
                while (!s.empty() && s.top() == expected) {
                    s.pop(); 
                    expected++;
                }
            } else {
                s.push(front);
            }
        }

        while (!s.empty()) {
            if (s.top() == expected) {
                s.pop();
                expected++;
            } else {
                return false;
            }
        }

        return true;
    }