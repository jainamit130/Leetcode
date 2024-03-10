class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int decrement=0;
        long long ans=0;
        while(happiness.size() && k>0 && happiness.back()>0){
            int t=happiness.back()-decrement;
            if(t<=0)
                break;
            ans+=t;
            k--;
            decrement++;
            happiness.pop_back();
        }
        return ans;
    }
};