class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> ans(n, -1); 
        dfs(0, 0, disappear, adjList, ans);
        
        return ans;
    }
    
    void dfs(int node, int time, vector<int>& disappear, vector<vector<pair<int,int>>>& adjList, vector<int>& ans) {
        if (time >= disappear[node]) return;
        
        if (ans[node] == -1 || time < ans[node]) {
            ans[node] = time;
        } else {
            return;
        }
        
        for (const auto& neighbor : adjList[node]) {
            int nextNode = neighbor.first;
            int nextTime = time + neighbor.second;
            dfs(nextNode, nextTime, disappear, adjList, ans);
        }
    }
};