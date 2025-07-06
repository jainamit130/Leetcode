class Solution {
public:
    bool doesAliceWin(string s) {
        int count=0;
        for(auto c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                count++;
            }
        }
        if(count==0){
            return false;
        }
        return true;
    }
};