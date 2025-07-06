class Solution {
public:
    int rootResult=0;
    vector<int> count;
    vector<int> result;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        count.resize(n,1);
        result.resize(n);
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        fillCountAndResultInit(adj,0,-1,0);
        result[0]=rootResult;
        for(int i=0;i<adj[0].size();i++){
            dfs(adj,adj[0][i],0,n);
        }
        return result;
    }

    int fillCountAndResultInit(vector<vector<int>>& adj,int currentNode,int parentNode,int depth){
        rootResult+=depth;
        for(int i=0;i<adj[currentNode].size();i++){
            if(adj[currentNode][i]!=parentNode)
                count[currentNode]+=fillCountAndResultInit(adj,adj[currentNode][i],currentNode,depth+1);
        }
        return count[currentNode];
    }

    void dfs(vector<vector<int>>& adj,int currentNode,int parentNode,int n){
        result[currentNode]=result[parentNode]-2*count[currentNode]+n;
        for(int i=0;i<adj[currentNode].size();i++){
            if(adj[currentNode][i]!=parentNode)
                dfs(adj,adj[currentNode][i],currentNode,n);
        }
        return;
    }
};