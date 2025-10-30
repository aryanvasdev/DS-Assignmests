int counts[2] = {0, 0}; 
        for (int student : students) {
            counts[student]++;
        }
        
        for (int sandwich : sandwiches) {
            if (counts[sandwich] == 0) {
                return counts[0] + counts[1];
            }
            counts[sandwich]--;
        }
        
        return 0;