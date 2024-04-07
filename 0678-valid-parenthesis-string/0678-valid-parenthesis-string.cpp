class Solution {
public:
    bool checkValidString(string s) {
        vector<vector<int>> cache(s.length()+1,vector<int>(s.length()+1,-1));
        return boolcheckValidity(0,0,s,cache);
    }

    bool boolcheckValidity(int index,int openBs,string s,vector<vector<int>>& cache){
        if(index>=s.length()){
            return openBs==0;
        }

        if(cache[index][openBs]!=-1)
            return cache[index][openBs];

        cache[index][openBs]=0;
        if(s[index]=='(')
            cache[index][openBs]|=boolcheckValidity(index+1,openBs+1,s,cache);
        if(s[index]==')')
            cache[index][openBs]|=boolcheckValidity(index+1,openBs-1,s,cache);
        if(s[index]=='*')
            cache[index][openBs]|=(boolcheckValidity(index+1,openBs+1,s,cache) || boolcheckValidity(index+1,openBs-1,s,cache) || boolcheckValidity(index+1,openBs,s,cache));
        return cache[index][openBs];
    }
};