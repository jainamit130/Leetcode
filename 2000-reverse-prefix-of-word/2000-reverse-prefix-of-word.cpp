class Solution {
public:
    string reversePrefix(string word, char ch) {
        string temp="";
        int i=0;
        int flag=0;
        for(;i<word.length();i++){
            temp+=word[i];
            if(word[i]==ch){
                flag=1;
                break;
            }
        }
        if(flag==0)
            return word;
        i++;
        int j=0,k=temp.length()-1;
        while(j<k){
            char c=temp[j];
            temp[j]=temp[k];
            temp[k]=c;
            j++;
            k--;
        }
        for(;i<word.length();i++)
            temp+=word[i];
        return temp;
    }
};