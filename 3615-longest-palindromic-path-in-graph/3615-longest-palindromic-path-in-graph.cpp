class Solution {
public:
    vector<vector<vector<int>>> cache;
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        vector<vector<int>> adj(n);
        // O(E)
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = 1;
        cache.resize(n+1,vector<vector<int>>(n+1,vector<int>(1<<14,-1)));
        // O(n)
        for(int i=0;i<n;i++) {
            // odd length
            ans = max(ans,1+solve(adj,i,i,0|(1<<i),label));
            // even length
            for(int j=0;j<adj[i].size();j++) {
                if(label[adj[i][j]]==label[i]) {
                    ans = max(ans,2+solve(adj,i,adj[i][j],0|(1<<i)|(1<<adj[i][j]),label));
                }
            }
        }
        return ans;
    }

    // node1 == ith pointer and node2==jth pointer
    int solve(vector<vector<int>>& adj,int node1,int node2,int mask,string& label) {
        if(cache[node1][node2][mask]!=-1) return cache[node1][node2][mask];
        int ans = 0;
        for(int i=0;i<adj[node1].size();i++) {
            int newNode1 = adj[node1][i];
            if( (mask>>newNode1) & 1) continue;
            for(int j=0;j<adj[node2].size();j++) {
                int newNode2 = adj[node2][j];
                if( (mask>>newNode2) & 1 || newNode1==newNode2) continue;
                if(label[newNode1]==label[newNode2]) {
                    ans = max(ans, 2 + solve(adj,newNode1,newNode2,mask | (1<<newNode1) | (1<<newNode2),label));
                }
            }
        }
        return cache[node1][node2][mask]=ans;
    }
};


/*
mask => 2^14

Steps

1. Build adj
2. iterate through nodes 
3. consider 2 cases 1 for odd length and the other for even length => for even length run of of neighbors from adj list
4. for all cases call the dp/recursive function => states: node1, node2, mask
5. memoize the function

b   c   a   b   b   a   c

even length => 
a   b   b   a
odd length => 
b   a   b

states => node1, node2


node1 -- node2


*/