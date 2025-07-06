class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int currCap = capacity;
        int i=0,j=0;
        int ans = 1;
        while(i<buses.size()) {
            if(currCap==0) {
                i++;
                currCap = capacity;
            } else if(i<buses.size() && j<passengers.size()) {
                if(passengers[j]>buses[i]) {
                    if(j==0 || (j>0 && passengers[j-1]!=buses[i])) ans = max(ans,buses[i]);
                    i++;
                    currCap = capacity;
                } else {
                    if(j==0 || (j>0 && passengers[j-1]!=passengers[j]-1)) ans = max(ans,passengers[j]-1);
                    currCap--;
                    j++;
                }
            } else {
                if(j>0 && passengers[j-1]!=buses[i]) ans = max(ans,buses[i]);
                currCap = capacity;
                i++;
            }
        }
        return ans;
    }
};


/*


10  20
        i


2   17  18  19
            j

capacity = 0
ans = 16

*/