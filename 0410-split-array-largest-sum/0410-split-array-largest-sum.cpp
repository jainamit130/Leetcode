class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans=r;
        while(l<=r){
            int mid = (l+r)/2;
            if(splitPossible(nums,mid,k)){
                //go left
                ans=mid;
                r=mid-1;
            } else {
                //go right
                l=mid+1;
            }
        }
        return ans;
    }

    bool splitPossible(vector<int>& nums,int threshold,int k){
        int sum=0;
        int subArray=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>threshold){
                subArray+=1;
                sum=nums[i];
            }
        }
        if(subArray+1<=k){
            return true;
        } 
        return false;
    }
};


/*
6   3   5   4   11  9


0   6   9   14  18  29  38

k=3



11 -> 38 

(11+16)/2 = 13 


6   3   5,4,11,9 => 29
6   3,5     4,11,9 => 24
6   3,5,4   11,9 => 20
6   3,5,4,11    9 => 23
6,3     5   4,11,9 => 24
6,3     5,4     11,9 => 20
6,3     5,4,11   9 => 20
6,3,5   4    11,9 => 20
6,3,5   4,11    9 => 15
6,3,5,4   11    9 => 18



x=


*/