class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int i=indexDifference,j1=-1,j2=-1,maxValue=INT_MIN,minValue=INT_MAX;
        int index=0;
        while(i<nums.size()){
            int addedDiff=nums[i]+valueDifference;
            int subDiff = nums[i]-valueDifference;
            if(maxValue<nums[index]){
                maxValue=nums[index];
                j1=index;
            }
            if(minValue>nums[index]){
                minValue=nums[index];
                j2=index;
            }
            if(maxValue>=addedDiff)
                return {j1,i};
            if(minValue<=subDiff)
                return {j2,i};
            index++;
            i++;
        }
        return {-1,-1};
    }
};