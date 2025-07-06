class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int totalK = count(nums.begin(),nums.end(),k);
        int extraK =0;
        for(int i=0;i<51;i++) {
            if(i==k) continue;
            int iToKCount = 0;
            int count = 0;
            for(int j=0;j<nums.size();j++) {
                if(nums[j]==i) {
                    count++;
                } else if(nums[j]==k) {
                    count--;
                }
                count = max(count,0);
                iToKCount = max(iToKCount,count);
            }
            extraK = max(iToKCount,extraK);
        }
        return totalK+extraK;
    }
};


/*

Some elements might already be k


Some elements need to be converted to k


k ...   5   k   6   5   5   .....   k


choose a element i from 0-50 as the element to be converted to k
if(i==k) loose a element => Hence consider it as -1
if(i==nums[i]) gain a element => Hence consider it as 1
else do nothing




k = 3
ans = 4




*/