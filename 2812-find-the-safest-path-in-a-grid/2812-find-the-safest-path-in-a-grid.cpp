class Solution {
public:


  vector<int> dr = {1, 0, -1, 0};
  vector<int> dc = {0, 1, 0, -1};
  
  bool isValid(int r, int c, int n, int m) {
    return (r >= 0 && r < n && c >= 0 && c < m);
  }


  void dfs(vector<vector<int>>& grid, vector<vector<int>>& dist) {
    int n = grid.size();
    queue<int> q; // row * n + col
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          dist[i][j] = 0;
          q.push(i * n + j);
        }
      }
    }
    while (!q.empty()) {
      int cell = q.front();
      q.pop();
      int r = cell / n, c = cell % n;
      for (int diff = 0; diff < 4; diff++) {
        int nr = r + dr[diff], nc = c + dc[diff];
        if (isValid(nr, nc, n, n) && dist[nr][nc] > 1 + dist[r][c]) {
          dist[nr][nc] = 1 + dist[r][c];
          q.push(nr * n + nc);
        }
      }
    }
  }


  int getPath(vector<vector<int>>& dist) {
    int n = dist.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;
    set<pair<int, int>, greater<pair<int, int>>> st; 
    
    st.insert({dist[0][0], 0});
    int sf = INT_MAX;
    while (!st.empty()) {
      auto [d, cell] = *(st.begin());
      st.erase(*(st.begin()));
      sf = min(sf, d);
      int r = cell / n, c = cell % n;
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (isValid(nr, nc, n, n) && !visited[nr][nc]) {
          st.insert({dist[nr][nc], nr * n + nc});
          visited[nr][nc] = true;
          if (nr == n - 1 && nc == n - 1) {
            sf = min(sf, dist[n - 1][n - 1]);
            return sf;
          }
        }
      }
    }
    return -1; 
  }

  int maximumSafenessFactor(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n -1][n - 1] == 1) return 0;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dfs(grid, dist);
    return getPath(dist);
  }
};