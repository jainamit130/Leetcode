using pii=pair<int,int>;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int threshold = pow(2, n) - 1;
        queue<pii> q;
        set<pii> visited;
        for (int i = 0; i < n; i++) {
            int val = 0;
            val = val | (1 << i);
            q.push({i, val});
        }
        int ans = 0;
        while (!q.empty()) {
            int size=q.size();
            while(size){
                int val = q.front().second;
                int node = q.front().first;
                q.pop();
                size--;
                if (visited.find({node, val}) != visited.end()) {
                    continue;
                }
                if (val == threshold) {
                    return ans;
                }
                visited.insert({node, val});
                for (int i = 0; i < graph[node].size(); i++) {
                    int newVal = val | (1 << graph[node][i]);
                    q.push({graph[node][i], newVal});
                }
            }
            ans++;
        }
        return -1;
    }
};