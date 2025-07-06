class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time=0;
        int totalWait=0;
        for(int i=0;i<customers.size();i++){
            time=max(time,customers[i][0]);
            int wait=max(time-customers[i][0],0)+customers[i][1];
            time+=customers[i][1];
            totalWait+=wait;
        }
        return (double)(totalWait/(double)customers.size());
    }
};

/*
[5,2] => 2  7
[5,4] => 6  11   
[10,3]=> 4  14
[20,1]=> 1  21



[1,2]
[2,5]
[4,3]


1   2
2   5
4   3

=> 
 


*/