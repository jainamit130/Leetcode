class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.length()!=s.length()){
            return false;
        }
        bool check = true;
        for(int shift = 0;shift<s.length();shift++){
            check = true;
            for(auto i=0;i<s.size();i++){
                if(s[(i+shift)%s.length()]!=goal[i]){
                    check=false;
                    break;
                }
            }
            if(check) return true;
        }
        return false;;
    }
};