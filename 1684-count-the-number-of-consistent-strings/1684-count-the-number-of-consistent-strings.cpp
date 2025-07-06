class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        long allowedChars = 0;
        for(auto c:allowed){
            int pos = c-'a';
            allowedChars = allowedChars | (1<<pos);
        }

        int ans=0;
        for(auto word:words){
            long currChars = 0;
            for(auto c:word){
                int pos = c-'a';
                currChars = currChars | (1<<pos);
                if(currChars > allowedChars){
                    break;
                }
            }
            currChars=currChars | allowedChars;
            if(allowedChars==currChars){
                ans++;
            }
        }
        return ans;
    }
};