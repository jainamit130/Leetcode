class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int ans=0;
        int t=0;
        for(int i=happiness.size()-1;i>=0 && k>0;i--){
            if((happiness[i]-t)<0)
                break;
            ans+=happiness[i]-t;
            t++;
            k--;
        }
        return ans;
    }
};