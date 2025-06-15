class Solution {
public:
    int n,maxPower;
    vector<vector<int>> ancestors;
    vector<long long> prefixWt;
    vector<int> levels;
    vector<int> findMedian(int _n,vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = _n;
        maxPower = log2(n)+1;
        vector<vector<vector<int>>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        ancestors.resize(n,vector<int>(maxPower,-1));
        prefixWt.resize(n,0);
        levels.resize(n,-1);
        bfsWithBinaryLifting(adj);
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            ans[i]=v;
            int lca = getLca(u,v);
            int dist = getDist(u,v);
            int target = (dist+1)/2;
            int nodeCount = levels[u]+levels[v]-2*levels[lca];
            int start = 0,end = nodeCount;
            int subAns = v;
            while(start<=end) {
                int mid = (start+end)/2;
                int guessedNode =  getMidNodeFromU(u,v,mid,lca);
                if(guessedNode==-1) break;
                if(getDist(u,guessedNode)>=target) {
                    subAns = guessedNode;
                    end = mid-1;
                } else {
                    start = mid+1;
                }
            }
            ans[i]=subAns;
        }
        return ans;
    }

    int getMidNodeFromU(int u,int v,int mid,int lca) {
        int nodeCountBetweenUAndLCA = levels[u]-levels[lca];
        if(mid<=nodeCountBetweenUAndLCA) {
            return lift(u,mid);
        }       
        int nodeCountBetweenVAndLCA = levels[v]-levels[lca];
        int rem = nodeCountBetweenVAndLCA - (mid - nodeCountBetweenUAndLCA);
        if(rem<0) return -1;
        return lift(v,rem);
    }

    int getDist(int u, int v) {
        int lca = getLca(u, v);
        return prefixWt[u] + prefixWt[v] - 2 * prefixWt[lca];
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

    int getLca(int u, int v) {
        if (levels[u] < levels[v]) swap(u, v);
        int diff = levels[u] - levels[v];

        u = lift(u, diff);
        if (u == v) return u;

        for (int i = maxPower - 1; i >= 0; i--) {
            if (ancestors[u][i] != -1 && ancestors[u][i] != ancestors[v][i]) {
                u = ancestors[u][i];
                v = ancestors[v][i];
            }
        }
        return ancestors[u][0];
    }


    void bfsWithBinaryLifting(vector<vector<vector<int>>>& adj) {
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