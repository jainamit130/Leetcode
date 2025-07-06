class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;

        // Construct Adj
        vector<vector<int>> adj1=construct(edges1);
        vector<vector<int>> adj2=construct(edges2);

        int maxDistTree2 = 0;
        for(auto i=0;i<m;i++) {
            maxDistTree2 = max(maxDistTree2,bfs(adj2,i,k-1));
        } 
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(bfs(adj1,i,k)+maxDistTree2);
        } 
        return ans;
    }

    int bfs(vector<vector<int>>& adj, int startNode, int threshold) {
        vector<int> visited(adj.size());
        queue<int> q;
        q.push(startNode);
        visited[startNode] = 1;
        int dist = 0;
        int ans = (threshold<0)?0:1;
        while(!q.empty()) {
            int size = q.size();
            while(size) {
                int node = q.front();
                q.pop();
                size--;
                for(auto neigh:adj[node]) {
                    if(!visited[neigh]) {
                        q.push(neigh);
                        visited[neigh]=1;
                    }
                }
            }
            dist++;
            if(dist<=threshold) {
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