class Solution {
public:
    typedef long long ll;
    long long maximumTotalCost(vector<int>& nums) {
        vector<pair<ll,ll>> p;
        int as=nums[0];
        int sa=nums[0];
        p.push_back({as,sa});
        for(int i=1;i<nums.size();i++){
            if(i%2==0){
                as+=nums[i];
                sa-=nums[i];
            } else {
                as-=nums[i];
                sa+=nums[i];
            }
            p.push_back({as,sa});
        }
        ll ans=as;
        for(int i=1;i<=nums.size();i++){
            ll t;
            if(i%2==0){
                t=p[i-1].second+p.back().first-p[i-1].first;
            } else {
                t=p[i-1].first+p.back().second-p[i-1].second;
            }
            ans=max(ans,t);
        }
        return ans;
    }
};