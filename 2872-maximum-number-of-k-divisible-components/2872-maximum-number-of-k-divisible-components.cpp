class Solution {
public:
    vector<int> visited;
    int ans;
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        visited.resize(n);
        visited[0]=1;
        ans = 0;
        dfs(visited,adj,values,k,0);
        return ans;
    }

    int dfs(vector<int>& visited,vector<vector<int>>& adj,vector<int>& values,int k,int node) {
        int sum = values[node];
        for(int i=0;i<adj[node].size();i++) {
            if(visited[adj[node][i]]!=1) {
                visited[adj[node][i]]=1;
                sum += dfs(visited,adj,values,k,adj[node][i]);
            }
        }
        if(sum%k==0) {
            ans++;
        }
        return sum;
    }
};

/*


valid split of the tree ios obtained by removing any set of edges possibly empty from the tree such that the resulting components all have values that are divisible by k



*/