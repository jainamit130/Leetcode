class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans;
        for(int j=k-1;j<n;j++){
            int sum = 0;
            unordered_map<int,int> mp;
            set<pair<int,int>> st;
            for(int i=j-k+1;i<=j;i++){
                sum+=nums[i];
                if(mp.find(nums[i])!=mp.end()){
                    st.erase({mp[nums[i]],nums[i]});
                }
                mp[nums[i]]++;
                st.insert({mp[nums[i]],nums[i]});
            }
            
            while(st.size()>x){
                auto [smallestFreq,smallestNum] = *st.begin();
                sum-=smallestFreq*smallestNum;
                st.erase({smallestFreq,smallestNum});
            }
            ans.push_back(sum);
        }
        return ans;
    }
};