class Solution {
public:
    bool isCircularSentence(string sentence) {

        char first=sentence[0];
        char last=sentence[sentence.size()-1];

        if(first!=last){
            return false;
        }
        bool iscircular=true;
        int f,l;
        for(int i=0;i<sentence.size()-1;i++){
            if(sentence[i]== ' '){
                if(sentence[i-1]==sentence[i+1]){
                    iscircular=true;
                }else{
                    iscircular=false;
                    break;
                }
            }
        }


        return iscircular;
    }
};