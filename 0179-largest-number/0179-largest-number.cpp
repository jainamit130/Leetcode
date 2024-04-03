class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](auto lhs,auto rhs){
            string temp=to_string(lhs);
            string temp1=to_string(rhs);
            return temp+temp1>temp1+temp;
        });
        string ans="";
        for(auto n:nums){
            if(ans=="0")
                ans="";
            ans+=to_string(n);
        }
        return ans;
    }
};



/*




*/