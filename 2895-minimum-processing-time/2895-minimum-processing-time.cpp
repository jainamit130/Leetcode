class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end(),[](auto& lhs,auto& rhs) {
            return lhs>rhs;
        });
        sort(processorTime.begin(),processorTime.end());
        int i = 0;
        int processorIndex = 0;
        int currTime = 0;
        while(i<tasks.size()) {
            int maxTaskTime = tasks[i];
            currTime = max(currTime,processorTime[processorIndex] + maxTaskTime); 
            processorIndex++;
            i+=4;
        }
        return currTime;
    }
};


/*
Given: processorTime => vector<int> => all non -ve int can be 0? yes
       tasks => vector<int> => all +ve int cannot be 0? yes

8   10


2   2   3   1   8   7   4   5


8   7   4   5
16

Sorting 
minHeap

*/