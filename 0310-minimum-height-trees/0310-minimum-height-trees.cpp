class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        } 
        vector<int> edgeCount(n);
        queue<int> leaves;
        for(int i=0;i<n;i++){
            if(adj[i].size()==1)
                leaves.push(i);
            edgeCount[i]=adj[i].size();
        }
        while(!leaves.empty()){
            if(n<=2){
                vector<int> ans;
                while(!leaves.empty()){
                    ans.push_back(leaves.front());
                    leaves.pop();
                }
                return ans;
            }
            int size=leaves.size();
            while(size){
                int node=leaves.front();
                leaves.pop();
                size--;
                n-=1;
                for(auto neighbour:adj[node]){
                    edgeCount[neighbour]-=1;
                    if(edgeCount[neighbour]==1)
                        leaves.push(neighbour);
                }
            }
        }
        return {0};
    }
};

/*

1   0
1   2
1   3



*/