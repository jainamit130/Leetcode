class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        sort(names.begin(),names.end(),[&heights](auto lhs,auto rhs){
            return lhs>rhs;
        });
        return names;
    }
};