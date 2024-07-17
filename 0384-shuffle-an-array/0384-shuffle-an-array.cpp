class Solution {
public:
    vector<int> original;
    Solution(vector<int>& nums) {
        original=nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        set<int> visited;
        vector<int> shuffled;
        int i=original.size();
        while(i){
            int t=rand()%original.size();
            if(visited.find(t)==visited.end()) {
                visited.insert(t);
                shuffled.push_back(original[t]);
                i--;
            }
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */