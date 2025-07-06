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
            cout<<maxValue<<" "<<minValue<<endl;
            index++;
            i++;
        }
        return {-1,-1};
    }
};



/*
A solution for question like to find two indices i and j, both in the range [0, n - 1], that satisfy the following conditions:

abs(i - j) = indexDifference, and
abs(nums[i] - nums[j]) = valueDifference

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        unordered_map<int,unordered_set<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].insert(i);
        }
        for(int i=0;i<nums.size();i++){
            vector<int> possibleValues= {nums[i]+valueDifference,nums[i]-valueDifference};
            vector<int> possibleIndexes= {i+indexDifference,i-indexDifference};
            for(auto a:possibleValues){
                if(a<0)
                    continue;
                for(auto b:possibleIndexes){
                    if(b<0 || b>=nums.size())
                        continue;
                    if(mp.find(a)!=mp.end() && mp[a].find(b)!=mp[a].end())
                        return {i,b};
                }
            }
        }
        return {-1,-1};
    }
};
*/