class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> indexes(s.length()+1,vector<int>(26,-1));
        for(int j=s.length()-1;j>=0;j--){
            indexes[j]=indexes[j+1];
            indexes[j][s[j]-'a']=j;
        }

        // for(int i=0;i<indexes.size();i++){
        //     cout<<i<<endl;
        //     for(int j=0;j<26;j++){
        //         if(indexes[i][j]!=-1){
        //             cout<<(char)(j+'a')<<" -> "<<indexes[i][j]<<endl;
        //         }
        //     }
        //     cout<<endl;
        // }

        int count=0;
        for(int i=0;i<words.size();i++){
            int flag=0;
            int driver=0;
            for(int j=0;j<words[i].size();j++){
                if(indexes[driver][words[i][j]-'a']!=-1){
                    driver=indexes[driver][words[i][j]-'a']+1;
                } else {
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                count++;
            }
        }
        return count;
    }
};