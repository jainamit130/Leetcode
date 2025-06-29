class Union {
    public:
        vector<int> parent;
        vector<int> rank;
        int components;
        Union(int n) {
            components=n;
            parent.resize(n);
            iota(parent.begin(),parent.end(),0);
            rank.resize(n);
        }

        Union(Union* root) {
            components=root->components;
            parent = root->parent;
            rank = root->rank;
        }

        int findParent(int n) {
            while(parent[n]!=n) n = parent[parent[n]];
            return n;
        }

        bool merge(int n1,int n2) {
            int p1 = findParent(n1);
            int p2 = findParent(n2);
            if(p1==p2) return false;
            if(rank[p1]>=rank[p2]) {
                parent[p2]=p1;
                rank[p1]++;
            } else {
                parent[p1]=p2;
                rank[p2]++;
            }
            components--;
            return true;
        }

        bool allConnected() {
            return components == 1;
        }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),[](auto& lhs,auto& rhs) {
            if(lhs[3]==rhs[3]) return lhs[2]>rhs[2];
            return lhs[3]<rhs[3];
        });

        Union* root = new Union(n);
        int minStart = getMinAfterTakingMustEdges(edges,root);
        if(minStart == -1) return -1;
        int ans = -1;
        int start = 0;
        int end = 2*1e5;
        while(start<=end) {
            Union* unionFind = new Union(root);
            int mid = start + (end-start)/2;
            if(isValid(edges,mid,k,unionFind)) {
                ans = mid;
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return min(ans,minStart);
    }

    bool isValid(vector<vector<int>>& edges,int stability,int k,Union* root) {
        for(auto edge:edges) {
            if(edge[3]) break;
            int strength = edge[2];
            int u = edge[0];
            int v = edge[1];
            if(!root->merge(u,v)) continue;
            if(strength>=stability) continue;
            if(k>0 && (strength*2)>=stability) {
                k--;
            } else {
                return false;
            }
        }
        return root->allConnected();
    }

    int getMinAfterTakingMustEdges(vector<vector<int>>& edges,Union* root) {
        int mini = INT_MAX;
        for(int i=edges.size()-1;i>=0;i--) {
            auto edge = edges[i];
            if(!edge[3]) break;
            if(!root->merge(edge[0],edge[1])) return -1;
            mini = min(edge[2],mini); 
        }
        return mini;
    }
};