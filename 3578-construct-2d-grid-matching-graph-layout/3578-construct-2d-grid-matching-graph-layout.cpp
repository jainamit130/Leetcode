vector<int> getPath(int src, int dest, vector<vector<int>> &adj) {
  int n = adj.size();
  auto bfs = [&](int src) {
    vector<int> dist(n, -1), from(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          from[v] = u;
          q.push(v);
        }
      }
    }
    return from;
  };
  vector<int> from = bfs(src), path;
  for (int node = dest; node != -1; node = from[node]) path.push_back(node);
  reverse(path.begin(), path.end());
  return path;
}

class Solution {
public:
    vector<vector<int>> handle1Dimension(vector<vector<int>>& adj) {
        int n = adj.size();
        int src = -1, dest = -1;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() > 1) continue;
            if (src == -1) src = i;
            else if (dest == -1) dest = i;
        }
        if (dest == -1) return {};
        vector<int> path = getPath(src, dest, adj);
        return { path };
    }
    
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        // Generate the adjacency list.
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Check for the edge case.
        vector<vector<int>> ans = handle1Dimension(adj);
        if (!ans.empty()) return ans;
        
        // Find out all the corners.
        vector<int> corners;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() > 2) continue;
            corners.push_back(i);
        }
        
        // Find an adjancent corner and the dimensions of the matrix.
        vector<int> paths_size = {
            static_cast<int>(getPath(corners[0], corners[1], adj).size()),
            static_cast<int>(getPath(corners[0], corners[2], adj).size()),
            static_cast<int>(getPath(corners[0], corners[3], adj).size())
        };
        int minIndex = min_element(paths_size.begin(), paths_size.end()) - paths_size.begin();
        int cols = paths_size[minIndex];
        int rows = n / cols;
        
        // Fill the first row of the matrix.
        ans = vector<vector<int>>(rows, vector<int>(cols, -1));
        ans[0] = getPath(corners[0], corners[minIndex + 1], adj);

        // Fill the rest of the rows, one by one.
        for (int r = 0; r < rows - 1; r++) {
            for (int c = 0; c < cols; c++) {
                // Find the neighbors that have already been placed.
                set<int> neighbors;
                if (r > 0) neighbors.insert(ans[r - 1][c]);
                if (c > 0) neighbors.insert(ans[r][c - 1]);
                if (c + 1 < cols) neighbors.insert(ans[r][c + 1]);
                
                // Place the neighbor that has not been placed yet.
                int u = ans[r][c];
                for (int v : adj[u]) {
                    if (!neighbors.contains(v)) {
                        ans[r + 1][c] = v;
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};