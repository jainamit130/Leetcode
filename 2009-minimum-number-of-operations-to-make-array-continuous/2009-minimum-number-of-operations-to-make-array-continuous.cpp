class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size=nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        nums.clear();
        nums.insert(nums.end(), st.begin(), st.end());
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int res=size;
        while(i<nums.size()){
            while(j<nums.size() && nums[j]<nums[i]+size){
                j++;
            }
            res=min(res,size-(j-i));
            i++;
        }
        return res;
    }
};


/*

8   10  16  18  10  10  16  13  13  16

8   10  10  10  13  13  16  16  16  18
    i
                                        j


*/