class Solution {
public:
    int mod = 1e9+7;
    
    int power(int base,int exp) {
        long long res = 1;
        long long b = base;
        while(exp) {
            if(exp%2) res = (res * b) % mod;
            b = (b*b)%mod;
            exp/=2;
        }
        return res;
    }
    
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+2;
        vector<vector<int>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int depth = 0;

        function<void(int,int,int)> dfs = [&](int u,int p,int d) {
            depth = max(depth,d);
            for(auto v:adj[u]) {
                if(v!=p) dfs(v,u,d+1);
            }
        };

        dfs(1,0,0);
        if(depth==0) return 1;
        return power(2,depth-1);
    }
};