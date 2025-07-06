class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<int>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = -1;
        for(auto edge:edges) {
            int u = edge[0];
            int v = edge[1];
            int subAns = scores[u]+scores[v];
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> neighU;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> neighV;
            // check and get max 3 neighbors of u except v
            for(auto neigh: adj[u]) {
                if(neigh == v) continue;
                neighU.push({scores[neigh],neigh});
                if(neighU.size()>3) {
                    neighU.pop();
                }
            }
            // check all neighbors of v except u
            for(auto neigh: adj[v]) {
                if(neigh == u) continue;
                neighV.push({scores[neigh],neigh});
                if(neighV.size()>3) neighV.pop();
            }
            while(!neighU.empty()) {
                auto [_,nodeU] = neighU.top();
                neighU.pop();
                priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> neighVCopy = neighV;
                while(!neighVCopy.empty()) {
                    auto [_,nodeV] = neighVCopy.top();
                    if(nodeV!=nodeU) ans = max(ans,subAns+scores[nodeV]+scores[nodeU]);
                    neighVCopy.pop();
                }
            }
        }
        return ans;
    }
};