class Solution {
public:
    int minNumberOperations(vector<int>& diff) {
        long long ans=abs(diff[0]);
        int prev=abs(diff[0]);

        for(int i=1;i<diff.size();i++){
            if((diff[i]<0 && diff[i-1]<0) || (diff[i]>0 && diff[i-1]>0)){
                if(prev<abs(diff[i])){
                    ans+=abs(diff[i])-prev;
                }
            } else {
                ans+=abs(diff[i]);
            }
            prev=abs(diff[i]);
        }
        return ans;
    }
};