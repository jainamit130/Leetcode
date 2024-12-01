class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        
        // Construct Adjacency List
        vector<vector<int>> adj1;
        adj1 = construct(edges1);

        vector<vector<int>> adj2;
        adj2 = construct(edges2); 

        vector<int> parityTree2(m,-1);
        bfs(0,adj2,parityTree2);
        int maxCount = max(count(parityTree2.begin(),parityTree2.end(),1),count(parityTree2.begin(),parityTree2.end(),0));
        
        vector<int> parityTree1(n,-1);
        bfs(0,adj1,parityTree1);
        int totalEven = count(parityTree1.begin(),parityTree1.end(),0);
        int totalOdd = count(parityTree1.begin(),parityTree1.end(),1);

        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(parityTree1[i]==0) {
                ans.push_back(totalEven + maxCount);
            } else {
                ans.push_back(totalOdd + maxCount);
            }
        }
        return ans;
    }

    void bfs(int startNode, vector<vector<int>>& adj,vector<int>& parity) {
        queue<int> q;
        
        q.push(startNode);
        parity[startNode] = 0;
        int bit = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size) {
                int node = q.front();
                q.pop();
                size--;
                for(auto neigh: adj[node]) {
                    if(parity[neigh]==-1) {
                        q.push(neigh);
                        parity[neigh] = bit;
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