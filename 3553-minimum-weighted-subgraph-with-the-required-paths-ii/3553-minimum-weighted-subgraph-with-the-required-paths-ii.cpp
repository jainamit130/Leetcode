class Solution {
public:
    int n,maxPower;
    vector<vector<int>> ancestors;
    vector<int> prefixWt,levels;
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size()+1;
        maxPower = log2(n)+1;
        vector<vector<vector<int>>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        ancestors.resize(n,vector<int>(maxPower,-1));
        prefixWt.resize(n,0);
        levels.resize(n,-1);
        bfs(adj);
        vector<int> ans;
        for(auto query:queries) {
            int src1 = query[0];
            int src2 = query[1];
            int dst = query[2];
            int dist = getDist(src1,src2) + getDist(src1,dst) + getDist(src2,dst);
            ans.push_back(dist/2);
        }
        return ans;
    }

    int getDist(int src1,int src2) {
        int level1 = levels[src1];
        int level2 = levels[src2];
        int diff = abs(level1-level2);
        int deeperNode = level1>level2? src1 : src2;
        int shallowNode = level1>level2? src2 : src1;
        int liftedNode = lift(deeperNode,diff);
        int lca = getLca(liftedNode,shallowNode);
        return prefixWt[src1]+prefixWt[src2]-2*prefixWt[lca];
    }

    int lift(int node,int lift) {
        int power = 0;
        while(lift) {
            if(lift&1) {
                node = ancestors[node][power];
            }
            power++;
            lift=lift>>1;
        }
        return node;
    }

    int getLca(int node1, int node2) {
        if(node1==node2) return node1;
        for(int power=maxPower-1;power>=0;power--) {
            if(ancestors[node1][power]!=-1 && ancestors[node1][power]!=ancestors[node2][power]) {
                node1 = ancestors[node1][power];
                node2 = ancestors[node2][power];
            }
        }
        return ancestors[node1][0];
    }

    void bfs(vector<vector<vector<int>>>& adj) {
        queue<int> q;
        q.push(0);
        prefixWt[0]=0;
        int level = 0;
        levels[0]=level;
        while(!q.empty()) {
            int size = q.size();
            level++;
            while(size--) {
                int node = q.front();
                q.pop();
                for(int i=0;i<adj[node].size();i++) {
                    int neigh = adj[node][i][0];
                    if(levels[neigh]==-1) {
                        levels[neigh]=level;
                        ancestors[neigh][0]=node;
                        prefixWt[neigh] = prefixWt[node]+adj[node][i][1];
                        for(int level=1;level<maxPower;level++) {
                            int parent = ancestors[neigh][level-1];
                            if(parent!=-1) {
                                ancestors[neigh][level] = ancestors[parent][level-1];
                            }
                        }
                        q.push(neigh);
                    }
                }
            }
        }
        return;
    }
};