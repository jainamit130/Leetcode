class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int ans = events[0][0];
        int longest_time = events[0][1];
        for(int i=1;i<events.size();i++) {
            if(longest_time<= events[i][1]-events[i-1][1]) {
                if(longest_time== events[i][1]-events[i-1][1]) {
                    ans=min(ans,events[i][0]);
                } else {
                    ans = events[i][0];
                }
                longest_time = events[i][1]-events[i-1][1];
            }
        }
        return ans;
    }
};