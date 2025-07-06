class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> adj(26);
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]!='!'){
                adj[equations[i][0]-'a'].push_back(equations[i][3]-'a');
                adj[equations[i][3]-'a'].push_back(equations[i][0]-'a');
            }
        }

        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='!'){
                int startNode=equations[i][0]-'a';
                int endNode=equations[i][3]-'a';
                vector<int> visited(26);
                if(!dfs(adj,startNode,endNode,visited)){
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& adj,int node,int endNode,vector<int>& visited){
        if(node==endNode){
            return false;
        }
        visited[node]=1;
        for(auto& nei:adj[node]){
            if(visited[nei]!=1){
                if(!dfs(adj,nei,endNode,visited)){
                    return false;
                }
            }
        }
        return true;
    }
};

/*

a==b
b==c
e==f
f==a

*/