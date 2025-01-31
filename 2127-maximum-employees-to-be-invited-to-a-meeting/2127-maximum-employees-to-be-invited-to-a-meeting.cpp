class Solution {
public:
    int maximumInvitations(vector<int>& adj) {
        int n = adj.size();
        vector<vector<int>> invertAdj(n);
        for(int i = 0; i < n; i++) {
            invertAdj[adj[i]].push_back(i);
        }

        vector<int> visited(n, 0);
        int longestClosedCycle = 0;
        int totalOpenCircle = 0;
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                vector<int> currTraversalVisitedSet(n, -1);
                visited[i] = 1;
                currTraversalVisitedSet[i] = 0;

                auto [node, cycleLength] = dfs(adj, adj[i], i, visited, currTraversalVisitedSet);
                
                if (cycleLength == 2) {
                    totalOpenCircle += bfs(invertAdj, adj[node], node) + bfs(invertAdj, node, adj[node]) + 2;
                } else {
                    longestClosedCycle = max(longestClosedCycle, cycleLength);
                }
            }
        }

        return max(totalOpenCircle, longestClosedCycle);
    }

    int bfs(vector<vector<int>>& adj, int node1, int node2) {
        queue<pair<int, int>> q;  // Use pair<int, int> to store the node and its distance
        int maxLen = 0;
        q.push({node1, 0});
        
        while (!q.empty()) {
            int node = q.front().first;
            int len = q.front().second;
            maxLen = max(maxLen, len);
            q.pop();
            
            for (int i = 0; i < adj[node].size(); i++) {
                if (adj[node][i] != node2) {  // Avoid going back to node2
                    q.push({adj[node][i], len + 1});
                }
            }
        }
        return maxLen;
    }

    pair<int, int> dfs(vector<int>& adj, int node, int prevNode, vector<int>& visited, vector<int>& currTraversalVisitedSet) {
        if (visited[node] == 1 && currTraversalVisitedSet[node] != -1) {
            return {node, currTraversalVisitedSet[prevNode] + 1 - currTraversalVisitedSet[node]};
        }
        if (visited[node] == 1) return {-1, 0};

        visited[node] = 1;
        currTraversalVisitedSet[node] = currTraversalVisitedSet[prevNode] + 1;
        return dfs(adj, adj[node], node, visited, currTraversalVisitedSet);
    }
};
