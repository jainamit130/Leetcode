class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int r=nums[0];
        for(int i=1;i<nums.size();i++){
            r^=nums[i];
        }
        int i=0;
        while(1){
            if((r>>i)&1)
                break;
            i++;
        }
        int a=0;
        int b=0;
        for(int j=0;j<nums.size();j++){
            if((nums[j]>>i)&1)
                a^=nums[j];
            else
                b^=nums[j];
        }
        return {a,b};
    }
};



// 1   2   1   3   2   5

// 3   ^   5

// 011 ^   101 =   110

// 0   0   0   0   1
// 0   0   0   1   0
// 0   0   0   0   1
// 0   0   0   1   0

// 0   0   0   1   1       

// 0   0   1   0   1

// 0   0   1   1   0

