class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        unordered_map<int,vector<int>> row;
        unordered_map<int,vector<int>> col;
        for(int i=0;i<n;i++){
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        vector<vector<int>> indegrees(n,{0,0});
        unordered_map<int,unordered_set<int>> adj;
        for(int k=0;k<=1;k++){
            unordered_map<int,vector<int>> mp;
            if(k==0){
                mp=row;
            } else {
                mp=col;
            }
            for(auto [a,b]:mp){
                for(int i=0;i<b.size()-1;i++){
                    for(int j=i+1;j<b.size();j++){
                        adj[b[i]].insert(b[j]);
                        adj[b[j]].insert(b[i]);
                        indegrees[b[i]]={indegrees[b[i]][0]+1,b[i]};
                        indegrees[b[j]]={indegrees[b[j]][0]+1,b[j]};
                    }
                }
            }   
        }
        int ans=0;
        while(indegrees.size()>0){
            sort(indegrees.begin(),indegrees.end(),greater<vector<int>>());
            while(indegrees.size()>0 && indegrees.back()[0]==0){
                indegrees.pop_back();
            }
            if(indegrees.size()==0){
                break;
            }
            int node=indegrees.back()[1];
            ans++;
            indegrees.pop_back();
            for(int i=0;i<indegrees.size();i++){
                if(adj[node].find(indegrees[i][1])!=adj[node].end()){
                    indegrees[i][0]--;
                }
            }
        }    
        return ans; 
    }
};