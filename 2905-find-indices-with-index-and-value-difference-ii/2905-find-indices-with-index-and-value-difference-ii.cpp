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




/*
Map
5 -> 0
1 -> 1  3
4 -> 2

indexDifference = 2    valueDifference = 4
0   1   2   3
5   1   4   1
i       j

possibleValues  -> >9    1>
possibleIndexes -> >=2   


5   1   4   1
i
        j

*/