class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for(auto n:arr) {
            if((n%2==0 && st.find(n/2)!=st.end()) || st.find(n*2)!=st.end()) {
                return true;
            } 
            st.insert(n);
        }
        return false;
    }
};