class Solution {
public:
    void dfs(int node, const unordered_map<int, unordered_set<int>>& adj, unordered_set<int>& visited, vector<int>& component) {
        stack<int> s;
        s.push(node);
        while (!s.empty()) {
            int curr = s.top();
            s.pop();
            if (visited.find(curr) == visited.end()) {
                visited.insert(curr);
                component.push_back(curr);
                for (int neighbor : adj.at(curr)) {
                    if (visited.find(neighbor) == visited.end()) {
                        s.push(neighbor);
                    }
                }
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> row;
        unordered_map<int, vector<int>> col;

        for (int i = 0; i < n; i++) {
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }

        unordered_map<int, unordered_set<int>> adj;
        for (int k = 0; k <= 1; k++) {
            unordered_map<int, vector<int>> mp;
            if (k == 0) {
                mp = row;
            } else {
                mp = col;
            }
            for (auto [a, b] : mp) {
                for (int i = 0; i < b.size() - 1; i++) {
                    for (int j = i + 1; j < b.size(); j++) {
                        adj[b[i]].insert(b[j]);
                        adj[b[j]].insert(b[i]);
                    }
                }
            }
        }

        unordered_set<int> visited;
        vector<int> components_sizes;
        
        for (const auto& [node, _] : adj) {
            if (visited.find(node) == visited.end()) {
                vector<int> component;
                dfs(node, adj, visited, component);
                components_sizes.push_back(component.size());
            }
        }

        int total_removals = 0;
        for (int size : components_sizes) {
            total_removals += size - 1; 
        }

        return total_removals;
    }
};