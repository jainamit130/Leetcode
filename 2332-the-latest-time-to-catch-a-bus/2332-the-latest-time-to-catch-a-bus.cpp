class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int i=0;
        int j=0;
        int ans=-1;
        while(i<buses.size()){
            int currentCap=0;
            while(j<passengers.size() && passengers[j]<=buses[i] && currentCap<capacity){
                if(j==0 || passengers[j-1]+1!=passengers[j]){
                    ans=passengers[j]-1;
                }
                currentCap++;
                j++;
            }
            if(j==0 || buses[i]!=passengers[j-1]){
                if(capacity>currentCap)
                    ans=buses[i];
            }
            currentCap=0;
            i++;
        }
        return ans;
    }
};



/*
10  20  30
i

4   11  13  19  21  25  26
    i

ans=10

capacity= 0


*/