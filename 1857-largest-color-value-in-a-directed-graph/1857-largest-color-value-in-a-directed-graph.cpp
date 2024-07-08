class Solution {
public:
    int flag=0;
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> adj(colors.length());
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        // for(int i=0;i<colors.length();i++){
        //     cout<<i<<" -> ";
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j]<<" ,";
        //     }
        //     cout<<endl;
        // }
        int ans=0;
        vector<int> visited(colors.length());
        vector<int> v(colors.length(),-1);
        for(int i=0;i<colors.length();i++){
            if(visited[i]==1 || v[i]!=-1){
                continue;
            }
            vector<int> alpha(26);
            int t=dfs(adj,i,alpha,visited,colors,v);
            if(flag){
                return -1;
            }
            ans=max(ans,t);
        }
        return ans;
    }

    int dfs(vector<vector<int>>& adj,int node,vector<int>& alpha,vector<int>& visited,string& colors,vector<int>& v){
        if(visited[node]){
            flag=1;
            return INT_MIN;
        }
        alpha[colors[node]-'a']++;
        visited[node]=1;
        v[node]=1;
        int t=alpha[colors[node]-'a'];
        for(int i=0;i<adj[node].size();i++){
            t=max(t,dfs(adj,adj[node][i],alpha,visited,colors,v));
        }
        visited[node]=0;
        alpha[colors[node]-'a']--;
        return t;
    }
};