class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> prefix(s.length()+1,vector<int>(26));
        for(int i=0;i<s.length();i++){
            prefix[i+1]=prefix[i];
            prefix[i+1][s[i]-'a']++;
        }
        vector<bool> result(queries.size());
        for(int i=0;i<queries.size();i++){
            int left=queries[i][0];
            int right=queries[i][1];
            int replace=queries[i][2];
            int odd=0;
            for(int j=0;j<26;j++){
                if((prefix[right+1][j]-prefix[left][j])%2!=0)
                    odd++;
            }
            while(replace>0 && odd>1){
                replace--;
                odd-=2;
            }
            if(odd<=1)
            {    cout<<i<<endl;result[i]=true;}
        }
        return result;
    }
};