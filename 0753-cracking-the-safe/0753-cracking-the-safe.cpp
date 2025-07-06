class Solution {
public:
    string ans;
    string crackSafe(int n, int k) {
        vector<vector<int>> adj(k);
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                adj[i].push_back(j);
            }
        }
        unordered_set<string> visited; 
        string curr="";
        dfs(adj,curr,0,visited,n);
        return ans;
    }

    bool dfs(vector<vector<int>>& adj,string curr,int node,unordered_set<string> visited,int n){
        if(curr.length()>=n && visited.find(curr.substr(curr.length() - n, n))!=visited.end()){
            return false;
        }

        string temp="";
        if(curr.length()>=n){
            temp=curr.substr(curr.length() - n, n);
            visited.insert(temp);
        }
        for(int i=0;i<adj[node].size();i++){
            if(dfs(adj,curr+to_string(adj[node][i]),adj[node][i],visited,n))
                return true;
        }
        if(ans.length()<curr.length()){
            ans=curr;
            if(ans.length()>=(pow(adj[0].size(),n)+n-1)){
                return true;
            }
        }
        return false;
    }
};


/*

00222121112201202101102001000

00033332323322322223331233132
31223131332123213221222131212
13311231132112211311121111333
02330133032302230123031302130
11303033202320132032202220122
03120212011203020203310231013
10321022101210311021101110301
02010103300230013003200220012
003100210011003000200010000


0001111010110010000
000222212122112111122201220212011202022101210211011102010102200120021001100200010000


000222212122112111122201220212011202022101210211011102010102200120021001100200010000


*/