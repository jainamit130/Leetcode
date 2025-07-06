class RandomizedCollection {
public:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> mp;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ans=false;
        if(mp.find(val)==mp.end())
            ans=true;
        mp[val].push_back(nums.size());
        nums.push_back({val,mp[val].size()-1});
        return ans;
    }
    
    bool remove(int val) {
        bool ans=false;
        if(mp.find(val)!=mp.end()) {
            ans=true;
            auto lastVal = nums.back();
            mp[lastVal.first][lastVal.second]=mp[val].back();
            nums[mp[val].back()]=lastVal;
            nums.pop_back();
            mp[val].pop_back();
            if(mp[val].empty()){
                mp.erase(val);
            }
        }
        return ans;
    }
    
    int getRandom() {
        int random_index = rand() % (nums.size());
        return nums[random_index].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */