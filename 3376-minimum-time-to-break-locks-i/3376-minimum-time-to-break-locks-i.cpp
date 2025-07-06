class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        return solve(strength,1,0,K);
    }

    int solve(vector<int>& strength,int factor,int visited,int& K) {
        if(visited==(1<<strength.size())-1){
            return 0;
        }
        int ans = INT_MAX;
        int temp = visited;
        for(int i=0;i<strength.size();i++) {
            if(((visited>>(strength.size()-1-i))&1)==0) {
                ans = min(ans,(int)ceil(strength[i]/(double)factor) + solve(strength,factor+K,visited|(1<<(strength.size()-1-i)),K));
            }
        }
        visited=temp;
        return ans;
    }
};