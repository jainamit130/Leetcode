class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(auto prerequisite:prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]);
        }
        vector<bool> ans;
        for(auto query:queries) {
            vector<int> visited(numCourses);
            visited[query[0]]=1;
            ans.push_back(dfs(adj,query[0],query[1],visited));
        }
        return ans;
    }

    bool dfs(vector<vector<int>>& adj,int node,int dst,vector<int>& visited) {
        if(node==dst) return true;
        bool ans = false;
        for(auto neigh:adj[node]) {
            if(visited[neigh]==0) {
                visited[neigh]=1;
                ans = ans || dfs(adj,neigh,dst,visited);
            }
        }
        return ans;
    }
};