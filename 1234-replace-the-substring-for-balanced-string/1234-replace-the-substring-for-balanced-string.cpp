class Solution {
public:
    vector<char> chs = {'Q','W','E','R'};
    int balancedString(string s) {
        // Creation of extras
        unordered_map<int,int> extras;
        for(auto ch:s) {
            extras[ch-'a']++;
        }
        int optimalCount = s.length()/4;
        for(auto [intCh,count]:extras) {
            extras[intCh] = count-optimalCount;
        }

        unordered_map<int,int> windowFreq;
        int i=0,j=0;
        int ans = compareFreq(windowFreq,extras)==0?0:s.length();
        if(ans==0) return 0;
        while(j<s.length()) {
            // Shrink
            while(i<j && compareFreq(windowFreq,extras)!=1) {
                ans = min(ans,j-i);
                windowFreq[s[i]-'a']--;
                i++;
            }
            // Expand
            windowFreq[s[j]-'a']++;
            j++;
        }
        return ans;
    }

    int compareFreq(unordered_map<int,int> windowFreq,unordered_map<int,int> extras) {
        int ans = 0;
        for(int ch:chs) {
            if(windowFreq[ch-'a'] - extras[ch-'a']>0) {
                ans = -1;
            } else if(windowFreq[ch-'a'] - extras[ch-'a']<0){
                return 1;
            }
        }
        return ans;
    }
};


/*

Ex:

shrink when more extras present and shrink till right extras present
expand when less extras present and expand till right extras reached
Compare windowFreq against extras => -1 - more extra
                                     0 - right extra
                                     1 - less extra

n/4 = 2
qwqqweew
qqqewwwwe
i want the smallest possible window with all the extras in that window

QQWE => q -> 2 W -> 1 E -> 1




*/