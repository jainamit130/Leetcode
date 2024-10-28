class Solution {
public:
    unordered_map<char,int> closest;
    vector<int> ans;
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        ans.resize(n);
        dfs(adj,s,0);
        return ans;
    }

    int dfs(vector<vector<int>>& adj,string& s,int node){
        int subTree = 1;

        int prevClosest = -1;
        if(closest.find(s[node])!=closest.end()){
            prevClosest=closest[s[node]];
        }

        closest[s[node]]=node;
        for(int i=0;i<adj[node].size();i++){
            int childNode = adj[node][i];
            if(closest.find(s[childNode])==closest.end() || s[node]==s[childNode]){
                subTree += dfs(adj,s,childNode);
            } else {
                ans[closest[s[childNode]]] += dfs(adj,s,childNode);
            }
        }

        if(prevClosest!=-1){
            closest[s[node]]=prevClosest;
        } else {
            closest.erase(s[node]);
        }

        ans[node]+=subTree;
        return ans[node];
    }
};


/*


closestAncestor = map<char,int>

*/