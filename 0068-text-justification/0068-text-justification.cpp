class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int c=0;
        string line=""; 
        vector<string> sentence;
        int i=0;
        int count=0;
        while(i<words.size()){
            if(c+words[i].length()<=maxWidth)
            {
                line+=words[i];
                line+=" ";
                c+=words[i].length();
                c++;
                count++;
            }
            else {
                line.pop_back();
                justify(line,count,maxWidth,0);
                sentence.push_back(line);
                line=words[i]+" ";
                c=words[i].length()+1;
                count=1;
            }
            i++;
        }
        line.pop_back();
        justify(line,count,maxWidth,1);
        sentence.push_back(line);
        return sentence;
    }

    void justify(string& line,int wordCount,int maxWidth,int last){
        int n=maxWidth-line.length();
        int flag=1;
        int copyWordCount=wordCount;
        //  cout<<line<<" "<<wordCount<<endl;
        if(!last) {
            if(wordCount!=1){
                while(copyWordCount!=0){
                    for(int j=0;j<line.length();j++){
                        if(line[j]==' ' && flag){
                            line.insert(j," ");
                            n--;
                            flag=0;
                            // cout<<line<<"1";
                            copyWordCount--;
                        } else if(line[j]!=' ' && !flag){
                            // cout<<"2";
                            flag=1;
                        }
                        if(n==0)
                            break;
                    }
                    if(n!=0)
                        copyWordCount=wordCount;
                    else
                        break;
                }
            }
            else{
                while(n){
                line+=' ';
                    n--; 
                }
            }
         } else {
             while(n){
                line+=' ';
                n--;  
             }
         }
    }
};