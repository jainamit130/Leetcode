class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        stack<pair<int,int>> st;
        int n=nums.size();
        vector<int> nextGreaterIndex(n);
        nextGreaterIndex[n-1]=n-1;
        st.push({n-1,nums.back()});
        int i=n-2;
        while(i>=0){
            while(!st.empty() && st.top().second<nums[i]){
                st.pop();
            }
            if(st.empty()){
                nextGreaterIndex[i]=n-1;
            } else {
                nextGreaterIndex[i]=st.top().first;
            }
            st.push({i,nums[i]});
            i--;
        }
        long long ans=0;
        i=0;
        while(i<n-1){
            ans+=(long long)nums[i]*(long long)(nextGreaterIndex[i]-i);
            i=nextGreaterIndex[i];
        }
        return ans;
    }
};