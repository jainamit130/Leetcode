class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string,int> mp;
        k = s.length()/k; // k now represents size of each substring
        for(int i=0;i<t.length();i+=k) {
            string str = "";
            for(int m=0;m<k;m++) {
                str+= t[i+m];
            }
            mp[str]++;
        }

        for(int i=0;i<s.length();i+=k) {
            string str = "";
            for(int m=0;m<k;m++) {
                str+= s[i+m];
            }
            if(mp.find(str)==mp.end()){
                return false;
            }

            mp[str]--;
            if(mp[str]==0){
                mp.erase(str);
            }
        }

        return true;
    }
};