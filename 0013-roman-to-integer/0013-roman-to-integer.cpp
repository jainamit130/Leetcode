class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
            };

        int a=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='I'){
                if(i<s.length()-1 && (s[i+1]=='V' || s[i+1]=='X')){
                    a+=mp[s[i+1]]-mp[s[i]];;
                    i++;
                } else {
                    a+=mp[s[i]];
                }
            } else if(s[i]=='X'){
                if(i<s.length()-1 && (s[i+1]=='L' || s[i+1]=='C')){
                    a+=mp[s[i+1]]-mp[s[i]];;
                    i++;
                } else {
                    a+=mp[s[i]];
                }
            } else if(s[i]=='C'){
                if(i<s.length()-1 && (s[i+1]=='D' || s[i+1]=='M')){
                    a+=mp[s[i+1]]-mp[s[i]];
                    i++;
                } else {
                    a+=mp[s[i]];
                }
            } else {
                a+=mp[s[i]];
            }
        }
        return a;
    }
};