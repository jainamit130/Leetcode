class Solution {
public:
    int possibleStringCount(string word) {
        char last = word[0];
        int count=1;
        int ans=1;
        for(int i=1;i<=word.length();i++){
            if(i<word.length() && word[i]==last){
                count++;
            } else {
                ans+=count-1;
                count=1;
                last=word[i];
            }
        }

        return ans;
    }
};