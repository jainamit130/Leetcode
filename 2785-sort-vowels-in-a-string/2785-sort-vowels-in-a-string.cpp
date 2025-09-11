class Solution {
public:
    string sortVowels(string s) {
        map<char,int> mp;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; 
        for(auto ch:s) {
            char copy = ch;
            if(vowels.find(tolower(copy))!=vowels.end()) mp[ch]++;
        } 

        string ans = "";
        for(auto ch:s) {
            char copy = ch;
            if(vowels.find(tolower(copy))!=vowels.end()) {
                auto vowelChar = mp.begin()->first;
                mp[vowelChar]--;
                ans.push_back(vowelChar);
                if(mp[vowelChar]==0) mp.erase(vowelChar);
            } else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};