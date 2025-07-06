class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<pair<int,int>>> revAdj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back({edge[1],edge[2]});
            revAdj[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<long long> src1ToAllDist(n,LLONG_MAX);
        shortestPath(adj,src1,src1ToAllDist);

        vector<long long> src2ToAllDist(n,LLONG_MAX);
        shortestPath(adj,src2,src2ToAllDist);

        vector<long long> destToAllDist(n,LLONG_MAX);
        shortestPath(revAdj,dest,destToAllDist);

        long long ans = LLONG_MAX;
        for(int i=0;i<n;i++) {
            if(src1ToAllDist[i]!=LLONG_MAX && src2ToAllDist[i]!=LLONG_MAX && destToAllDist[i]!=LLONG_MAX)
                ans = min(ans,src1ToAllDist[i]+src2ToAllDist[i]+destToAllDist[i]);
        }
        return ans==LLONG_MAX?-1:ans;
    }

    void shortestPath(vector<vector<pair<int,int>>>& adj,int src,vector<long long>& srcToAllDist) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        srcToAllDist[src]=0;
        while(!pq.empty()) {
            auto [weight,node] = pq.top();
            pq.pop();
            if(weight>srcToAllDist[node]) continue;
            srcToAllDist[node] = weight;
            for(int i=0;i<adj[node].size();i++) {
                auto [neighNode,neighWeight] = adj[node][i];
                pq.push({neighWeight+weight,neighNode});
            }
        }
        return;
    }
};