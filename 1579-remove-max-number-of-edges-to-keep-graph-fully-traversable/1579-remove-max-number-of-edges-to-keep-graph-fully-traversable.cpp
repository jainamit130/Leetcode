class Union {
    vector<int> parent;
    vector<int> rank;
    public:
    int components;
    Union(int n){
        components=n;
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int find(int element){
        int p=element;
        while(parent[p]!=p){
            parent[p]=find(parent[parent[element]]);
            p=parent[p];
        }
        return p;
    }

    bool unionElements(int n1,int n2){
        int p1=find(n1);
        int p2=find(n2);
        if(p1==p2){
            return false;
        } 
        components--;
        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        } else if(rank[p1]<rank[p2]){
            parent[p1]=p2;
        } else {
            parent[p2]=p1;
            rank[p1]+=1;
        }
        return true;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Union* alice=new Union(n);
        Union* bob=new Union(n);
        int ans=0;
        sort(edges.begin(),edges.end(),greater<vector<int>>());
        for(int i=0;i<edges.size();i++){
            int n1=edges[i][1]-1;
            int n2=edges[i][2]-1;
            if(edges[i][0]==3){
                bool a=alice->unionElements(n1,n2);
                bool b=bob->unionElements(n1,n2);
                if(a || b) {
                    ans++;
                }
            } else if(edges[i][0]==1){
                if(alice->unionElements(n1,n2)){
                    ans++;
                }
            } else {
                if(bob->unionElements(n1,n2)){
                    ans++;
                }
            }
        }
        if(alice->components!=1 || bob->components!=1)
            return -1;
        return edges.size()-ans;
    }
};