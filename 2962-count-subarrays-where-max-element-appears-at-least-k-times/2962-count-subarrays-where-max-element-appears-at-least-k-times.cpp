class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement=INT_MIN;
        for(auto n:nums)
            maxElement=max(maxElement,n);
        int i=0,j=0;
        int count=0;
        long long ans=nums.size()*(nums.size()+1)/2;
        while(j<nums.size()){
            // cout<<i<<" "<<j<<endl;
            if(nums[j]==maxElement)
                count++;
            j++;
            while(count==k){
                if(nums[i]==maxElement)
                    count--;
                i++;
            }
            ans=ans-(j-i);
        }
        return ans;
    }
};


/*

1   3   2   3   3
        i   
                j


3 => 3(4)/2 => 6
2 => 2(3)/2 => 3
total subarrays => 5*6/2 => 15
15-6-3=

*/