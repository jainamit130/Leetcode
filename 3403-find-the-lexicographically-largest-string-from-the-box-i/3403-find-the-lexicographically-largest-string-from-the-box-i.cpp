class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) {
            return word;
        }

        string ans = "a";
        for(int i=0;i<word.length();i++) {
            if(word[i]>=ans[0]) {
                string subAns = word.substr(i,min(word.length() - i,word.length() - numFriends + 1));
                if(subAns>ans) {
                    ans=subAns;
                }
            }
        }
        return ans;
    }
};


/*


word.length() - largestSubString.length() = numFriends - 1

largestSubString.length() = word.length() - numFriends + 1

*/