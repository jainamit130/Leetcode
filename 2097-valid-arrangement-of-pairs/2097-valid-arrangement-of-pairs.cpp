class Solution {
public:
    vector<int> path;
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> outDegrees;
        unordered_map<int,int> inDegrees;
        for(int i=0;i<pairs.size();i++) {
            adj[pairs[i][0]].push_back(pairs[i][1]);
            outDegrees[pairs[i][0]]++;
            inDegrees[pairs[i][1]]++;
        }
        int start = pairs[0][0];
        for(auto [node,_]:adj) {
            int diff = outDegrees[node]-inDegrees[node];
            if(diff==1) {
                start = node;
                break;
            }
        }
        dfs(adj,start);
        vector<vector<int>> ans;
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size()-1;i++) {
            ans.push_back({path[i],path[i+1]});
        }
        return ans;
    }

    void dfs(unordered_map<int,vector<int>>& adj,int node) {
        while(!adj[node].empty()) {
            int neigh = adj[node].back();
            adj[node].pop_back();
            dfs(adj,neigh);
        }
        path.push_back(node);
        return;
    }
};



/*
4   5
5   1
9   4
11  9

4 -> 5
5 -> 1
9 -> 4
11 -> 9
*/