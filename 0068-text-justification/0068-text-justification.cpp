class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        queue<string> q;
        vector<string> ans;
        int count=0;
        int i=0;
        while(i<words.size()){
            if(count+words[i].length()-1>=maxWidth){
                count--;
                int diff=maxWidth-count;
                int gaps=q.size()-1;
                int extras=0;
                int evenD=0;
                if(gaps>0){
                    extras=diff%gaps;
                    evenD=diff/gaps;
                }
                diff=diff-extras-evenD*gaps;
                string line="";
                while(!q.empty()){
                    line+=q.front();
                    if(gaps>0) {
                        line+=" ";
                        for(int j=0;j<evenD;j++){
                            line+=" ";
                        }
                        if(extras>0){
                            line+=" ";
                            extras--;
                        }
                        gaps--;
                    } 
                    q.pop();
                }
                for(int i=0;i<diff;i++){
                    line+=" ";
                }
                ans.push_back(line);
                count=0;
                if(i==words.size()){
                    break;
                }
            } else {
                count+=words[i].length()+1;
                q.push(words[i]);
                i++;
            }
        }
        string line="";
        int remaining=maxWidth;
        while(!q.empty()){
            line+=q.front();
            remaining-=q.front().length();
            q.pop();
            if(q.size()){
                line+=" ";
                remaining--;
            } else {
                while(remaining){
                    line+=" ";
                    remaining--;
                }
            }
        }
        ans.push_back(line);
        return ans;
    }
};


/*
["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]




*/