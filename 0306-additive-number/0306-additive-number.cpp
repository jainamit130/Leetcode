class Solution {
public:
    bool isAdditiveNumber(string nums) {
        if (nums.length() < 3) return false;
        bool ans = false;
        for(int len1=1;len1<nums.length()-1;len1++) {
            for(int len2=1;max(len1,len2)<=(nums.length()-len1-len2);len2++) {    
                ans = ans || solve(nums,0,len1,len1,len2);
            }
        }
        return ans;
    }

    int solve(string nums,int start1,int start2,int len1,int len2) {
        if((nums[start1]=='0'&& len1>1) || (nums[start2]=='0' && len2>1)) return false;
        if(start2+len2>=nums.length()) return true;
        long thirdNum = stoll(nums.substr(start1,len1)) + stoll(nums.substr(start2,len2));
        string thirdNumStr = to_string(thirdNum);
        if(thirdNumStr == nums.substr(start2+len2,thirdNumStr.length())) {
            return solve(nums,start2,start2+len2,len2,thirdNumStr.length());
        }
        return false;
    }
};


/*

        E       l2  
x   x   x   x   x   x   x   x   x   x



*/