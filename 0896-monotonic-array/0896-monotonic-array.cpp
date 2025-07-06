class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return solve(nums,0,nums.size()-1,nums[0]<=nums.back());
    }

    bool solve(vector<int>& nums,int start,int end,bool isInc) {
        if(start>=end) return true;

        int mid = start+(end-start)/2;
        if((nums[start]<nums[mid])!=isInc && nums[start]!=nums[mid]) {
            return false;
        }

        if((nums[mid]<nums[end])!=isInc && nums[mid]!=nums[end]) {
            return false;
        }

        bool ans = true;
        ans = ans && solve(nums,start,mid-1,isInc) && solve(nums,mid+1,end,isInc);
        return ans;
    }
};

// class Solution {
// public:
//     bool isMonotonic(vector<int>& nums) {
//         bool inc = true;
//         bool dec = true;
//         for(int i=0;i<nums.size()-1;i++) {
//             if(nums[i]>nums[i+1]) inc=false;
//             if(nums[i]<nums[i+1]) dec=false;
//             if(!inc && !dec) return false;
//         }   
//         return true;
//     }
// };


/*

Binary Search

get mid point


1   2   3   2   4   5   6   3   5   6
0   1   2   3   4   5   6   7   8   9

get 4 and run a recursion on 0-3 and 5-9

0-3
get mid point = 1

2-3
get mid point = 2
2<3 => false 

5-9






*/