class Solution {
public:
    int ans=0;
    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return ans;
    }

    vector<int> mergeSort(vector<int>& nums,int l,int r){
        if(l==r){
            return {nums[l]};
        }

        vector<int> merged;
        if(l<r){
            int mid = (l+r)/2;
            vector<int> left=mergeSort(nums,l,mid);
            vector<int> right=mergeSort(nums,mid+1,r);
            for(int i=0;i<left.size();i++){
                int start=0,end=right.size()-1;
                int index = -1;
                while(start<=end){
                    int m = (start+end)/2;
                    if((long long)2*right[m]<left[i]){
                        index=m;
                        start=m+1;
                    } else{
                        end=m-1;
                    }
                }
                ans+=index+1;
            }   
            merged = merge(left,right);
        }
        return merged;
    }

    vector<int> merge(vector<int>& left,vector<int>& right){
        int i=0,j=0;
        vector<int> arr;
        while(i<left.size() && j<right.size()){
            if(left[i]<right[j]){
                arr.push_back(left[i]);
                i++;
            } else {
                arr.push_back(right[j]);
                j++;
            }
        }

        while(i<left.size()){
            arr.push_back(left[i]);
            i++;
        }

        while(j<right.size()){
            arr.push_back(right[j]);
            j++;
        }
        return arr;
    }
};

// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         vector<int> sorted;
//         int n=nums.size();
//         int ans=0;
//         // n*n*log(n)*log(n)
//         for(int i=n-1;i>=0;i--){
//             int target = (nums[i]/2)-(nums[i]%2==0);
//             int index = upper_bound(sorted.begin(),sorted.end(),target)-sorted.begin();
//             ans+=index;
//             sorted.push_back(nums[i]);
//             sort(sorted.begin(),sorted.end());
//         }
//         return ans;
//     }
// };