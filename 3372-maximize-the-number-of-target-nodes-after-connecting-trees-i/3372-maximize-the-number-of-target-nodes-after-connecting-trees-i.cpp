class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        
        // Construct Adjacency List
        vector<vector<int>> adj1;
        adj1 = construct(edges1);

        vector<vector<int>> adj2;
        adj2 = construct(edges2); 

        int maxDist = 0;
        for(int i=0;i<m;i++) {
            maxDist = max(bfs(i,adj2,k-1),maxDist);
        }
        vector<int> ans;
        for(int i=0;i<n;i++) {
            ans.push_back(bfs(i,adj1,k)+maxDist);
        }
        return ans;
    }

    int bfs(int startNode, vector<vector<int>>& adj, int k) {
        int dist = 0;
        queue<int> q;
        int ans = 1;
        if(k<0){
            return 0;
        }
        vector<int> visited(adj.size());
        q.push(startNode);
        visited[startNode] = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size) {
                int node = q.front();
                q.pop();
                size--;
                for(auto neigh: adj[node]) {
                    if(!visited[neigh]) {
                        q.push(neigh);
                        visited[neigh] = 1;
                    }
                }
            }
            dist++;
            if(dist<=k) {
                ans+=q.size();
            } else {
                break;
            }
        }
        return ans;
    }

    vector<vector<int>> construct(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
};