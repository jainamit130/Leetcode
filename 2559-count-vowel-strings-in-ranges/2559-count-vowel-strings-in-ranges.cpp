class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> st = { 'a','e','i','o','u' };
        vector<int> prefix;
        prefix.push_back(0);
        for(auto str:words) {
            prefix.push_back(prefix.back());
            if(st.find(str[0])!=st.end() && st.find(str.back())!=st.end()) {
                prefix[prefix.size()-1]=prefix.back()+1;
            }
        }
        vector<int> ans;
        for(auto query:queries) {
            ans.push_back(prefix[query[1]+1]-prefix[query[0]]);
        }
        return ans;
    }
};