class Solution {
public:
    long long wonderfulSubstrings(string word) {
        string xors="0000000000";
        unordered_map<string,int> mp;
        mp[xors]++;
        long long result=0;
        for(auto c:word){
            xors[c-'a'] = ((xors[c-'a']-'0')^1)+'0';
            if(mp.find(xors)!=mp.end()){
                result+=mp[xors];
            } 
            for(char ch='a';ch<='j';ch++){
                string copy=xors;
                copy[ch-'a'] = ((copy[ch-'a']-'0')^1)+'0';
                if(mp.find(copy)!=mp.end())
                    result+=mp[copy];
            }
            mp[xors]++;
        }
        return result;
    }
};

/*


a   a   b   b
i

result=0

mp
0000 -> 1



*/