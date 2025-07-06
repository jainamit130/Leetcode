class Solution {
public:
    using ll = long long;
    vector<vector<ll>> cache;
    ll maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n=edges.size()+1;
        vector<vector<vector<int>>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }

        cache.resize(n+1,vector<ll>(2,-1));
        return solve(adj,0,k,0,0); // adj, node, k, parent ,isParentRem
    }

    ll solve(vector<vector<vector<int>>>& adj,int node,int k, int parent, int isParentRem) {
        if(cache[node][isParentRem]!=-1) {
            return cache[node][isParentRem];
        }
        
        ll ans = 0;
        int noOfEdgesToRem = max(0,(int)adj[node].size()-isParentRem-k);
        vector<pair<ll,ll>> takeNotTakeOnChildren;
        for(auto neigh: adj[node]) {
            if(neigh[0]!=parent) {
                ll take = neigh[1] + solve(adj,neigh[0],k,node,0);
                ll notTake = solve(adj,neigh[0],k,node,1);
                takeNotTakeOnChildren.push_back({take,notTake});
            }
        }

        sort(takeNotTakeOnChildren.begin(),takeNotTakeOnChildren.end(),[](auto lhs,auto rhs) {
            return lhs.first - lhs.second < rhs.first - rhs.second; 
        });
        for(int i=0;i<takeNotTakeOnChildren.size();i++) {
            if(i<noOfEdgesToRem) {
                ans+=takeNotTakeOnChildren[i].second;
            } else {
                ans+=max(takeNotTakeOnChildren[i].first,takeNotTakeOnChildren[i].second);
            }
        }
        return cache[node][isParentRem]=ans;
    }
};