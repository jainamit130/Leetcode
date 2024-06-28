class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        long long ans=0;
        vector<int> degrees(n);
        for(int i=0;i<degrees.size();i++){
            degrees[i]=adj[i].size();
        }
        sort(degrees.begin(),degrees.end());
        for(int i=0;i<n;i++){
            ans+=(long long)(i+1)*(long long)degrees[i];
        }
        return ans;
    }
};