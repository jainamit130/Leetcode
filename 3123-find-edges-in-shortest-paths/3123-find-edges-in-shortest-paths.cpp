class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);
        dijkstraAlgo(adj,0,dist1);
        dijkstraAlgo(adj,n-1,dist2);
        vector<bool> ans(edges.size());
        int i=0;
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            cout<<dist1[u]<<" "<<dist2[u]<<" "<<dist1[v]<<" "<<dist2[v]<<endl;
            if((dist1[u]!=INT_MAX && dist2[u]!=INT_MAX && dist1[v]!=INT_MAX && dist2[v]!=INT_MAX) && (dist1[u]+dist2[v]+e[2]==dist1[n-1] || dist1[v]+dist2[u]+e[2]==dist1[n-1]))
                ans[i]=true;
            i++;
        }
        return ans;
    }

    void dijkstraAlgo(vector<vector<pair<int,int>>>& adj,int source,vector<int>& dist){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,source});
        while(!pq.empty()){
            auto [wt,dst]=pq.top();
            pq.pop();
            if(dist[dst]<wt)
                continue;
            dist[dst]=wt;
            for(auto [newdst,newwt]:adj[dst]){
                pq.push({newwt+wt,newdst});
            }
        }
    }
};

/*

0   1   2   3   4   5
0   4   1   2

visited:    0   2   3   1 

Source = 3

PQ:
4,1,0


*/