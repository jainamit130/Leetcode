class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int start=0;
        int end=nums.back()-nums[0];
        while(start<end){
            int mid=(start+end)/2;
            int c=count(nums,mid);
            if(c>=k){
                end=mid;
            } else if(c<k){
                start=mid+1;
            } 
        }
        return start;
    }

    int count(vector<int>& nums,int len){
        int i=0,j=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]-nums[i]<=len){
                ans+=j-i;
                j++;
            } else {
                while(i<j && nums[j]-nums[i]>len){
                    i++;
                }
            }
        }
        return ans;   
    }
};


/*
Pairs having diff<=len O(n^2)
Total Pairs - Pairs having diff>len 

0   1   2   3   4   5   6   7   8   9
1   1   3   3   3   4   4   4   5   5
        i   
                                        j
<=3

1+2+3+4+5+6+7+6+7
3+3+9+12+14
26+6+9
32+9
41


1   1   3
        i
            j

<=48




*/