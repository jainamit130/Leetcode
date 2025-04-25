class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> visited(n);
        vector<vector<int>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        long long total = 0;
        long long ans = 0;
        for(int i=0;i<n;i++) {
            if(visited[i]==0) {
                visited[i]=1;
                int nodesCount = 1+dfs(visited,adj,i);
                ans += nodesCount*total;
                total += nodesCount;
            }
        }
        return ans;
    }

    int dfs(vector<int>& visited,vector<vector<int>>& adj,int node) {
        int ans = 0;
        cout<<node<<endl;
        for(int i=0;i<adj[node].size();i++) {
            if(visited[adj[node][i]]==0) {
                visited[adj[node][i]]=1;
                ans += 1+dfs(visited,adj,adj[node][i]);
            }
        }
        return ans;
    }
};


/*


0   2   4   5 => 4
 
1   6 => 2

3 => 1


1   2   4
ans = 2 + 12
3
1      2     4

*/