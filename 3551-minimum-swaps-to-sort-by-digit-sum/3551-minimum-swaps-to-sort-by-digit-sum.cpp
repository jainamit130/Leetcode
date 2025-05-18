class Solution {
public:
    int getDigitsSum(int n) {
        int sum = 0;
        while(n) {
            sum +=n%10;
            n/=10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        vector<int> sortedIndexes(nums.size());
        iota(sortedIndexes.begin(),sortedIndexes.end(),0);
        sort(sortedIndexes.begin(),sortedIndexes.end(),[&](auto lhs,auto rhs) {
            int sumLhs = getDigitsSum(nums[lhs]);
            int sumRhs = getDigitsSum(nums[rhs]);
            if(sumLhs==sumRhs) return nums[lhs]<nums[rhs];
            return sumLhs<sumRhs;
        });

        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            if(sortedIndexes[i]==i) continue;
            else {
                swap(sortedIndexes[i],sortedIndexes[sortedIndexes[i]]);
                ans++;
                i--;
            }
        }
        return max(ans,0);
    }
};



/*

0   1   2   3   4   5   6
17  4   29  13  6   5   8


5   4   29  13  6   17  8

29  4   5   13  6   17  8

8   4   5   13  6   17  29

6   4   5   13  8   17  29

13  4   5   6   8   17  29

4   13  5   6   8   17  29


1   3   5   4   6   0   2
4   4   5   6   8   8   11










*/