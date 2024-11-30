class Solution {
public:
    vector<vector<int>> ans;
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
        cout<<start<<endl;
        dfs(adj,start);
        return ans;
    }

    void dfs(unordered_map<int,vector<int>>& adj,int node) {
        while(!adj[node].empty()) {
            int nextNode = adj[node].back();
            adj[node].pop_back();
            ans.push_back({node,nextNode});
            dfs(adj,nextNode);
        }
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