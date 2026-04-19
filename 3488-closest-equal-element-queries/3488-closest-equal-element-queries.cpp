class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> indexMp;
        for(int i=0;i<nums.size();i++) {
            indexMp[nums[i]].push_back(i);
        }

        vector<int> ans;
        for(auto index:queries) {
            int dist = INT_MAX;
            auto mpIndex = lower_bound(indexMp[nums[index]].begin(),indexMp[nums[index]].end(),index)-indexMp[nums[index]].begin();
            // check 1 index before
            int beforeIndex = mpIndex-1;
            if(beforeIndex>=0) dist = min(dist,abs(index-indexMp[nums[index]][beforeIndex]));
            // check 1 index after
            int afterIndex = mpIndex+1;
            if(afterIndex<indexMp[nums[index]].size()) dist = min(dist,abs(index-indexMp[nums[index]][afterIndex]));
            // extreme left check
            if(!indexMp[nums[index]].empty() && indexMp[nums[index]][0]!=index) {
                int diff = abs(indexMp[nums[index]][0]-index);
                dist = min({dist,diff,(int)nums.size()-diff});
            }
            // extreme right check
            if(!indexMp[nums[index]].empty() && indexMp[nums[index]].back()!=index) {
                int diff = abs(indexMp[nums[index]].back()-index);
                dist = min({dist,diff,(int)nums.size()-diff});
            }
            ans.push_back(dist==INT_MAX?-1:dist); 
        }
        return ans;
    }
};


/*
0   1   2   3   4   5   6
1   3   1   4   1   3   2
i

     0   1   2
1 -> 0   2   4
2 -> 6 
3 -> 1,5
4 -> 3


0   1   2   3   4   5

0   3   5



*/