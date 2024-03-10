class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double average=0;
        double maxAverage=INT_MIN;
        int i=0;int j=0;
        int sum=0;
        while(j<nums.size()){
            if(j-i+1<=k){
                sum+=nums[j];
                j++;
            } else {
                average=(double)sum/k;
                maxAverage=max(maxAverage,average);
                sum-=nums[i];
                sum+=nums[j];
                i++;j++;
            }
        }
        average=(double)sum/k;
        maxAverage=max(maxAverage,average);
        return maxAverage;
    }
};