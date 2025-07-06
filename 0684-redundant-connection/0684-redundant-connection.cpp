class UnionFind {
    vector<int> rank;
    vector<int> parent;
    public:
    UnionFind(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    int find(int node){
        if(parent[node]==node)
            return parent[node];
        node=find(parent[parent[node]]);
        return node;
    }

    bool performUnion(int n1,int n2){
        int p1=find(n1);
        int p2=find(n2);

        if(p1==p2)
            return false;

        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
            rank[p1]+=1;
        } else if(rank[p2]>rank[p1]){
            parent[p1]=p2;
            rank[p2]+=1;
        } else {
            parent[p2]=p1;
            rank[p1]+=1;           
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind u(edges.size());
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            if(!u.performUnion(edges[i][0],edges[i][1]))
                ans={edges[i][0],edges[i][1]};
        }
        return ans;
    }
};