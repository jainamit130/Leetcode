class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);
        int ans = -1;
        int currMaxDist = INT_MAX;
        bfs(dist1,node1,edges);
        bfs(dist2,node2,edges);

        for(int i=0;i<n;i++) {
            if(dist1[i]!=-1 && dist2[i]!=-1 && currMaxDist>max(dist1[i],dist2[i])) {
                ans = i;
                currMaxDist = max(dist1[i],dist2[i]);
            }
        }
        return ans;
    }

    void bfs(vector<int>& dist,int node,vector<int>& edges) {
        queue<int> q;
        q.push(node);
        dist[node]=0;
        while(!q.empty()) {
            int currNode = q.front(); 
            q.pop();
            int neigh = edges[currNode];
            if(neigh!=-1 && dist[neigh]==-1) {
                dist[neigh]=dist[currNode]+1;
                q.push(neigh);
            }
        }    
        return;
    }
};