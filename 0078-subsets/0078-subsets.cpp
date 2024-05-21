class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return helper(nums,-1,nums.size()-1);
    }
private:
    map<pair<int,int>, vector<vector<int>> > mem;
    
    vector<vector<int>> helper(vector<int> nums, int begin, int end){
        
        pair<int,int> key = make_pair(begin,end);
        if(mem.find(key) != mem.end())return mem[key];
        
        vector<vector<int>> subsets;
        vector<int> empty_v;
        subsets.push_back(empty_v);
        
        if(begin > end){
            return subsets;
        }
        for(int i = begin+1; i<=end; i++){
            vector<vector<int>> result = helper(nums,i,end);
            for(int j = 0; j<result.size(); j++){
                result[j].push_back(nums[i]);
            }
            subsets.insert(subsets.end(),result.begin(), result.end());
        }
        mem.insert(make_pair(key,subsets));
        return subsets;
    }
};