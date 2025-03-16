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
            int beforeIndex = mpIndex-1;
            if(beforeIndex>=0) {
                dist = min(dist,(int)abs(index-indexMp[nums[index]][beforeIndex]));
            }

            int afterIndex = mpIndex+1;
            if(afterIndex!=indexMp[nums[index]].size()) {
                dist = min(dist,(int)abs(index-indexMp[nums[index]][afterIndex]));
            }

            // wrap around cases
            if(!indexMp[nums[index]].empty() && indexMp[nums[index]][0]!=index) {
                dist = min({dist,(int)nums.size()-(int)abs(indexMp[nums[index]][0]-index)});
            }

            if(!indexMp[nums[index]].empty() && indexMp[nums[index]].back()!=index) {
                dist = min({dist,(int)nums.size()-(int)abs(indexMp[nums[index]].back()-index)});
            }
            ans.push_back(dist==INT_MAX?-1:dist);
        }
        return ans;
    }
};


/*

1   3   1   4   1   3   1
0   1   2   3   4   5   6
i

1 -> 0,2,4
2 -> 6
3 -> 1,5
4 -> 3

*/