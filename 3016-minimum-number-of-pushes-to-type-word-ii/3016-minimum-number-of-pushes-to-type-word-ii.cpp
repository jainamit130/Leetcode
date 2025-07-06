class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26);
        int count = 1;
        int c = 0;
        for (int i = 0; i < word.size(); i++) {
            mp[word[i] - 'a']++;
        }
        sort(mp.begin(), mp.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (mp[i] == 0) {
                break;
            }
            ans += count * mp[i];
            c++;
            if (c % 8 == 0) {
                c = 0;
                count++;
            }
        }
        return ans;
    }
};