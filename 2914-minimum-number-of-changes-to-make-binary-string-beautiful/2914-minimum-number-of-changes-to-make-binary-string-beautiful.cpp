class Solution {
public:
        int minChanges(string word) {
        int count=1;
        char last = word[0];
        int ans=0;
        for(int i=1;i<=word.length();i++){
            if(i<word.length() && word[i]==last){
                count++;
            } else {
                if(count%2==1){
                    ans++;
                    i++;
                }
                if(i==word.length()){
                    break;
                }
                last=word[i];
                count=1;
            }
        }
        return ans;
    }
};