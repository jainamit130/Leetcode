class dsu {
    public:
    vector<int> parent,rank;
    vector<int> weights;
    dsu(int n){
        parent.resize(n);
        rank.resize(n);
        weights.resize(n,INT_MAX);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int leader(int n){
        if(n==parent[n]) return n;
        return leader(leader(parent[n]));
    }

    void merge(int n1,int n2,int w){
        int p1=leader(n1);
        int p2=leader(n2);
        weights[p1]=weights[p1]&w;
        weights[p2]=weights[p2]&w;
        weights[p1]=weights[p1]&weights[p2];
        weights[p2]=weights[p2]&weights[p1];
        if(p1==p2) return;
        else if(rank[p1]>rank[p2]) {
            parent[p2]=p1;
            // cout<<"1 -> "<<w<<" "<<weights[p1]<<endl;
        }
        else if(rank[p1]<rank[p2]) {
            parent[p1]=p2;
            // cout<<"2 -> "<<w<<" "<<weights[p2]<<endl;
        }
        else {
            parent[p2]=p1;
            rank[p1]++;
            // cout<<"3 -> "<<w<<" "<<weights[p1]<<endl;
        }
        return;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        dsu d(n);
        for(auto e:edges)
            d.merge(e[0],e[1],e[2]);
        vector<int> res;
        for(auto q:query){
            if(q[0]==q[1]){
                res.push_back(0);
                continue;
            }
            int p1=d.leader(q[0]);
            int p2=d.leader(q[1]);
            if(p1!=p2)
                res.push_back(-1);
            else {
                res.push_back(d.weights[p1]);
            }
        }
        return res;
    }
};


/*


0   1   7
1   3   7
1   2   1
          -> 
0 -> 1 <
          ->  
*/