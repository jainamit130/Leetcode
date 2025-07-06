class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++) {
            adj[i].push_back(i+1);
        }

        vector<int> ans;
        for(auto q:queries) {
            adj[q[0]].push_back(q[1]);
            ans.push_back(bfs(adj));
        }

        return ans;
    }

    int bfs(vector<vector<int>>& adj) {
        vector<int> visited(adj.size());
        queue<int> q;
        q.push(0);
        visited[0]=1;
        int dist = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size) {
                int node = q.front();
                size--;
                q.pop();
                if(node==adj.size()-1) {
                    return dist;
                }
                for(auto neigh:adj[node]) {
                    if(visited[neigh]==0) {
                        q.push(neigh);
                        visited[neigh] = 1;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};


/*

    0   1   2   3   4
1                   
2
3


*/