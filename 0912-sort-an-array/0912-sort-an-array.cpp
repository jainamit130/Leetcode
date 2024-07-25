// Insertion Sort O(n^2) Best Case O(n)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            int j=i-1;
            while(j>=0 && nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                j--;
            }
        }
        return nums;
    }
};

// Selection Sort O(n^2)
// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         int n=nums.size();
//         for(int i=1;i<n;i++){
//             int mini=nums[i-1];
//             int loc=i-1;
//             for(int j=i;j<n;j++){
//                 if(mini>nums[j]){
//                     mini=nums[j];
//                     loc=j;
//                 }
//             }
//             swap(nums[i-1],nums[loc]);
//         }
//         return nums;
//     }
// };

// Modified Bubble Sort O(n^2) Best Case O(n)
// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         int n=nums.size();
//         for(int i=0;i<n-1;i++){
//             int flag=0;
//             for(int j=0;j<n-1-i;j++){
//                 if(nums[j]>nums[j+1]) {
//                     swap(nums[j],nums[j+1]);
//                     flag=1;
//                 }
//             }
//             if(flag==0){
//                 return nums;
//             }
//         }
//         return nums;
//     }
// };

// Bubble Sort O(n^2)
// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         int n=nums.size();
//         for(int i=0;i<n-1;i++){
//             for(int j=0;j<n-1-i;j++){
//                 if(nums[j]>nums[j+1])
//                     swap(nums[j],nums[j+1]);
//             }
//         }
//         return nums;
//     }
// };