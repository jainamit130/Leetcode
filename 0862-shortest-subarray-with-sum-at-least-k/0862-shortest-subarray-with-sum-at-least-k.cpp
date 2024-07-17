class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long> prefix;
        vector<int> indexes;
        prefix.push_back(0);
        indexes.push_back(-1);
        int ans=INT_MAX;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(!prefix.empty() && sum<prefix.back()){
                prefix.pop_back();
                indexes.pop_back();
            }
            prefix.push_back(sum);
            indexes.push_back(i);
            int diff=sum-k;
            int index=lower_bound(prefix.begin(),prefix.end(),diff)-prefix.begin();
            if(index<prefix.size() && diff!=prefix[index]){
                index--;
            }
            if(index>=0 && index<indexes.size()){
                ans=min(ans,i-indexes[index]);
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};