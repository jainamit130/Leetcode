class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int suffixCount = 0;
        int suffixAns = 0;
        for(int i=boxes.size()-1;i>=0;i--){
            suffixAns+=suffixCount;
            if(boxes[i]=='1')
                suffixCount+=1;
        }
        int prefixCount=0;
        int prefixAns=0;
        for(int i=0;i<nums.length();i++) {
            
            prefixAns+=prefixCount;
            if(nums[i]=='1') {
                prefixCount++;
            }
            ans.push_back(prefixAns+suffixAns);
            if(nums[i]=='1') {
                suffixCount--;
            }
            suffixAns-=suffixCount;
        }
        return ans;
    }
};