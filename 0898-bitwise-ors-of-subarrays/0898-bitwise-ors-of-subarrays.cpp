class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev,curr,ans;
        for(int i=0;i<arr.size();i++) {
            for(auto s:prev) {
                curr.insert(s|arr[i]);
                ans.insert(s|arr[i]);
            }
            curr.insert(arr[i]);
            ans.insert(arr[i]);
            prev=curr;
            curr.clear();
        }
        return ans.size();
    }
};