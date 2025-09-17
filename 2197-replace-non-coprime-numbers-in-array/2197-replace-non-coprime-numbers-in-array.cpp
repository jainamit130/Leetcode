class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int idx=0;
        int curr=nums[0];
        vector<int> st;
        while(idx<nums.size()){
            if(st.empty() || __gcd(st.back(),curr)==1){
                st.push_back(curr);
                idx++;
                if(idx>=nums.size()) break;
                curr=nums[idx];
            }
            else{
                int top=st.back();
                st.pop_back();
                curr=lcm(top,curr);
            }
        }
        return st;
    }
};