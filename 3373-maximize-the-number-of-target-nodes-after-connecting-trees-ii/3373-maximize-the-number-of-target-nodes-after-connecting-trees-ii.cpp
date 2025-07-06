class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;

        // Construct Adj list
        vector<vector<int>> adj1 = construct(edges1);
        vector<vector<int>> adj2 = construct(edges2);

        vector<int> parity2(m,-1); // Tree2
        vector<int> parity1(n,-1); // Tree1

        bfs(0,adj2,parity2);
        bfs(0,adj1,parity1);

        int maxTree2 = max(count(parity2.begin(),parity2.end(),0),count(parity2.begin(),parity2.end(),1));

        int countEven = count(parity1.begin(),parity1.end(),0);
        int countOdd = count(parity1.begin(),parity1.end(),1);
         
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(parity1[i]==0) {
                // Take the count of 0 + Tree2 Count
                ans.push_back(countEven+maxTree2);
            } else {
                // Take the count of 1 + Tree2 Count
                ans.push_back(countOdd+maxTree2);
            }
        }
        return ans;
    }

    void bfs(int startNode,vector<vector<int>>& adj,vector<int>& parity) {
        queue<int> q;
        q.push(startNode);
        parity[startNode] = 0; // Even Node
        int bit = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size){
                int node = q.front();
                q.pop();
                size--;
                for(auto neigh:adj[node]) {
                    if(parity[neigh]==-1) {
                        parity[neigh]=bit;
                        q.push(neigh);
                    }
                }
            }
            bit=!bit;
        }
        return;
    }

    vector<vector<int>> construct(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }

};