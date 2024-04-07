// #Approach 1
// class Solution {
// public:
//     int longestMonotonicSubarray(std::vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;

//         int maxLength = 1;

//         int increasingLength = 1;
//         int decreasingLength = 1;

//         for (int i = 1; i < n; ++i) {
//             if (nums[i] > nums[i - 1]) {
//                 increasingLength++;
//                 decreasingLength = 1;
//             } else if (nums[i] < nums[i - 1]) {
//                 decreasingLength++;
//                 increasingLength = 1;
//             } else {
//                 increasingLength = 1;
//                 decreasingLength = 1;
//             }

//             maxLength = max(maxLength, max(increasingLength, decreasingLength));
//         }

//         return maxLength;
//     }
// };

// #Approach 2
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int len=1;
        int len1=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])
                len++;
            else{
                ans=max(len,ans);
                len=1;
            }
            if(nums[i]<nums[i-1])
                len1++;
            else{
                ans=max(len1,ans);
                len1=1;
            }
        }
        ans=max(len1,ans);
        ans=max(len,ans);
        return ans;
    }
};


/*


1   4   3   3   2
            i

*/