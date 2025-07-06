class Solution {
public:
    unordered_map<char,int> mp = {{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}};
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> minIndex;
        minIndex[0]=-1;
        int mask = 0;
        int result=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                mask = mask ^ (1<<mp[s[i]]);
                if(minIndex.find(mask)!=minIndex.end()){
                    result=max(result,i-minIndex[mask]);
                } else {
                    minIndex[mask] = i;
                }
            } else {
                if(minIndex.find(mask)!=minIndex.end()){
                    result=max(result,i-minIndex[mask]);
                }
            }
        }
        return result;
    }

    bool isVowel(char ch){
        if(mp.find(ch)!=mp.end()){
            return true;
        }
        return false;
    }
};