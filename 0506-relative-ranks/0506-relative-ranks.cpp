class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans; 
        bool gold=false,silver=false,bronze=false;
        for(auto n:score){
            if(n==1)
                ans.push_back("Gold Medal");
            else if(n==2){
                ans.push_back("Silver Medal");
            }
            else if(n==3){
                ans.push_back("Bronze Medal");
            } else {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};