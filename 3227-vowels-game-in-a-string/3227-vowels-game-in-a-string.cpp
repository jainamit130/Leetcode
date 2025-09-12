class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> vowel = {'a','e','i','o','u'};
        for(auto ch:s) {
            if(vowel.find(ch)!=vowel.end()) return true;
        }
        return false;
    }
};

/*






*/

