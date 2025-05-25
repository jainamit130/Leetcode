class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int equalDouble = 0;
        string st = "";
        unordered_map<string,int> ed;
        unordered_map<string,int> mp;
        string lookup = "";
        for(auto word:words) {
            lookup = word;
            reverse(lookup.begin(),lookup.end());
            if(word[1]==word[0]) {
                ed[word]++;
            } else if (mp.find(lookup)!=mp.end()) {
                mp[lookup]--;
                ans+=4;
                if(mp[lookup]==0) mp.erase(lookup);
            } else {
                mp[word]++;
            }
        }
        for(auto [str,freq]:ed) {
            if(freq%2!=0 && equalDouble<2*freq) {
                st = str;
                equalDouble = 2*freq;
            } 
        }

        for(auto [str,freq]:ed) {
            if(str==st) continue;
            freq = freq - (freq%2!=0);
            ans += freq*2;
        }
        return ans+equalDouble;
    }
};


/*


ccbbaaddddddddddaabbcc

aa

bb

cc

*/