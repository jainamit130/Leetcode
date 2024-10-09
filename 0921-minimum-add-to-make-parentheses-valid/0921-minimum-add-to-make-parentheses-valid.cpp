class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt1 = 0, cnt2 = 0;
        for(auto c: s){
            if(c==')'){
                if(cnt1>0){
                    cnt1--;
                }else{
                    cnt2++;
                }
            }else{
                cnt1++;
            }
        }
        return cnt1 + cnt2;
    }
};