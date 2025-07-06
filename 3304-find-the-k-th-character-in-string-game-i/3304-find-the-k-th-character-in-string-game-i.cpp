class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(k>=word.length()){
            string nextWord="";
            for(auto ch:word){
                if(ch=='z'){
                    nextWord+='a';
                } else {
                    nextWord+=ch+1;
                }
            }
            word+=nextWord;
        }
        return word[k-1];
    }
};