class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }

    void mergeSort(vector<int>& nums,int l,int h){
        if(l>=h){
            return;
        }

        int mid=(l+h)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,h);
        merge(nums,l,mid,h);
        return;
    }

    void merge(vector<int>& nums,int l,int mid,int h){
        vector<int> newNums;
        int i=l;
        int j=mid+1;
        while(i<=mid && j<=h){
            if(nums[i]<nums[j]){
                newNums.push_back(nums[i]);
                i++;
            } else {
                newNums.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            newNums.push_back(nums[i]);
            i++;
        }
        while(j<=h){
            newNums.push_back(nums[j]);
            j++;
        }
        int k=0;
        for(int i=l;i<=h;i++){
            nums[i]=newNums[k];
            k++;
        }
        return;
    }
};

//Quick Sort O(n log n) worst case O(n^2)
// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         int n=nums.size();
//         quickSort(nums,0,n-1);
//         return nums;
//     }

//     void quickSort(vector<int>& nums,int l,int h){
//         if(l<h){
//             int mid=partition(nums,l,h);
//             quickSort(nums,l,mid);
//             quickSort(nums,mid+1,h);
//         }
//         return;
//     }

//     int partition(vector<int>& nums, int l, int h) {
//         int pivot = nums[l];
//         int i = l - 1;
//         int j = h + 1;

//         while (true) {
//             do {
//                 i++;
//             } while (nums[i] < pivot);

//             do {
//                 j--;
//             } while (nums[j] > pivot);

//             if (i >= j)
//                 return j;

//             swap(nums[i], nums[j]);
//         }
//     }
// };

// Insertion Sort O(n^2) Best Case O(n)
// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         int n=nums.size();
//         for(int i=1;i<n;i++){
//             int j=i-1;
//             while(j>=0 && nums[j]>nums[j+1]){
//                 swap(nums[j],nums[j+1]);
//                 j--;
//             }
//         }
//         return nums;
//     }
// };

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