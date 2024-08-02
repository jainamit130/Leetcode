class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(i!=headID)
                adj[manager[i]].push_back(i);
        }
        
        return solve(adj,0,headID,informTime);
    }

    int solve(vector<vector<int>>& adj,int time,int node,vector<int>& informTime){
        
        if(adj[node].size()==0){
            return time;
        }

        int ans=0;
        for(int i=0;i<adj[node].size();i++){
            ans=max(ans,solve(adj,time+informTime[node],adj[node][i],informTime));
        }
        return ans;
    }
};