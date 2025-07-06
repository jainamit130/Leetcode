class Solution {
public:
    string customSortString(string order, string s) {
        vector<char> orderMap(26);
        for(int i=0;i<order.length();i++){
            orderMap[order[i]-'a']=i;
        }
        sort(s.begin(),s.end(),[&](auto lhs,auto rhs){        
            return orderMap[lhs-'a']<orderMap[rhs-'a'];
        });
        return s;
    }
};