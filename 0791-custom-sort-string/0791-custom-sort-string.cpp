class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> orderMap;
        for(int i=0;i<order.length();i++){
            orderMap[order[i]]=i;
        }
        sort(s.begin(),s.end(),[&](auto lhs,auto rhs){        
            return orderMap[lhs]<orderMap[rhs];
        });
        return s;
    }
};