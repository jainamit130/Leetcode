class UnionFind{
    public:
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n){
        for(int i=0;i<=n;i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int findParent(int element){
        int p=element;
        while(parent[p]!=p){
            parent[p]=findParent(parent[parent[element]]);
            p=parent[p];
        }
        return p;
    }

    bool unionize(int n1,int n2){
        int p1=findParent(n1);
        int p2=findParent(n2);
        if(p1==p2){
            return true;
        }

        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        } else if(rank[p1]<rank[p2]){
            parent[p1]=p2;
        } else {
            parent[p2]=p1;
            rank[p1]+=1;
        }
        return false;
    } 
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        UnionFind* u=new UnionFind(edges.size());
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            if(u->unionize(edges[i][0],edges[i][1])){
                ans={edges[i][0],edges[i][1]};
            }
        }
        return ans;
    }
};