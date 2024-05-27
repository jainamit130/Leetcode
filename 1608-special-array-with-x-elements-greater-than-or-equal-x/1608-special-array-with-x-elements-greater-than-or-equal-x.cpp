class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<=1000;i++){
            //binary search
            int ans = nums.size()-(lower_bound(nums.begin(),nums.end(),i)-nums.begin());
            if(ans==i)
                return ans;
        }
        return -1;
    }
};

/*

1   2   3   4   5   6
0

*/