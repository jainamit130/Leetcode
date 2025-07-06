class Solution {
public:
    bool isNumber(string s) {
        if(s[0]=='.' && s.length()>=2 && s[1]=='e')
            return false;
        bool num=false,e=false,symbol=false,dot=false,checkNumberAfterDot=false,checkNumberAfterSymbol=false;
        if(s[0]=='e')
            return false;
        unordered_set<int> numbers={'0','1','2','3','4','5','6','7','8','9'};
        for(auto c:s){
            if(e){
                if(c=='.')
                    return false;
                else if(!symbol && (c=='+' || c=='-'))
                    symbol=true;
                else if(numbers.find(c)==numbers.end())
                    return false;
                else {
                    num=true;
                    symbol=true;
                }
            } else {
                if(!dot && c=='.') {
                    cout<<"broo";
                    dot=true;
                    checkNumberAfterDot=true;
                }
                else if(!checkNumberAfterSymbol && (c=='e' || c=='E')) {
                    if(e)
                        return false;
                    else
                        e=true;
                }
                else if(!checkNumberAfterDot && !symbol && (c=='+' || c=='-')) {
                    symbol=true;
                    checkNumberAfterDot=true;
                    checkNumberAfterSymbol=true;
                }
                else if(numbers.find(c)==numbers.end()) 
                    return false;
                else {
                    checkNumberAfterDot=false;
                    num=true;
                    symbol=true;
                }
            }
        }
        if(s.back()=='e' || s.back()=='E')
            return false; 
        return num;
    }
};


/*

"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"

"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"

*/