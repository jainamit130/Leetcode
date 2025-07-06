class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowAdj(k+1);
        vector<vector<int>> colAdj(k+1);
        for(int i=0;i<rowConditions.size();i++){
            rowAdj[rowConditions[i][1]].push_back(rowConditions[i][0]);
        }

        for(int i=0;i<colConditions.size();i++){
            colAdj[colConditions[i][1]].push_back(colConditions[i][0]);
        }
        vector<int> visited(k+1);
        vector<int> globalVisited(k+1);
        vector<int> leftToRight;
        for(int i=1;i<=k;i++){
            if(!traverse(colAdj,i,visited,globalVisited,leftToRight))
                return {};
        }

        fill(visited.begin(),visited.end(),0);
        fill(globalVisited.begin(),globalVisited.end(),0);
        vector<int> topToBottom;
        for(int i=1;i<=k;i++){
            if(!traverse(rowAdj,i,visited,globalVisited,topToBottom))
                return {};
        }

        unordered_map<int,int> mp;
        for(int i=0;i<leftToRight.size();i++){
            mp[leftToRight[i]]=i;
        }

        vector<vector<int>> ans(k,vector<int>(k));
        for(int i=0;i<topToBottom.size();i++){
            ans[i][mp[topToBottom[i]]]=topToBottom[i];
        }
        return ans;
    }

    bool traverse(vector<vector<int>>& adj,int node,vector<int> visited,vector<int>& globalVisited,vector<int>& storeTopo){
        if(visited[node]){
            return false;
        }
        
        if(globalVisited[node]){
            return true;
        }
        

        globalVisited[node]=1;
        visited[node]=1;
        bool valid=true;
        for(int i=0;i<adj[node].size();i++){
            if(!traverse(adj,adj[node][i],visited,globalVisited,storeTopo)){
                return false;
            }
        }
        visited[node]=0;
        storeTopo.push_back(node);
        return true;
    }
};