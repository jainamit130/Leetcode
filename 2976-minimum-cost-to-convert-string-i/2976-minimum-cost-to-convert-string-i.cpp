class Solution {
public:
    using ll =long long;
    ll minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> distances(26,vector<ll>(26,INT_MAX));
        for (int i = 0; i < original.size(); i++) {
            distances[original[i]-'a'][changed[i]-'a']=min(distances[original[i]-'a'][changed[i]-'a'],(ll)cost[i]);
        }    

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    distances[i][j]=min(distances[i][j],distances[i][k]+distances[k][j]);
                }
            }
        }

        long long ans=0;
        for(int i=0;i<source.size();i++){
            int src=source[i]-'a';
            int dst=target[i]-'a';
            if(src==dst)
                continue;
            if(distances[src][dst]==INT_MAX)
                return -1;
            ans+=distances[src][dst];
        }   
        return ans;
    }
};


// class Solution {
// public:
//     long long minimumCost(string source, string target, vector<char>& original,
//                           vector<char>& changed, vector<int>& cost) {

//         vector<vector<vector<int>>> adj(26);
//         for (int i = 0; i < original.size(); i++) {
//             adj[original[i]-'a'].push_back({changed[i]-'a', cost[i]});
//         }

//         int ans = 0;
//         vector<vector<int>> distances(26, vector<int>(26, INT_MAX));
//         for (int i = 0; i < target.size(); i++) {
//             int src = source[i]-'a';
//             int dst = target[i]-'a';
//             if(src==dst){
//                 continue;
//             }

//             if (distances[src][dst] == INT_MAX) {
//                 vector<vector<int>> visited(26, vector<int>(26));
//                 solve(distances, src, dst, adj,visited);
//                 if (distances[src][dst] == INT_MAX){
//                     return -1;
//                 }
//             }
//             ans += distances[src][dst];
//         }
//         return ans;
//     }

//     void solve(vector<vector<int>>& distances, int& src, int& dst,
//                vector<vector<vector<int>>>& adj,vector<vector<int>>& visited) {
//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
//             pq;
//         pq.push({0, src,src});
//         while (!pq.empty()) {
//             int node = pq.top()[1];
//             int cost = pq.top()[0];
//             int lastNode=pq.top()[2];
//             pq.pop();
//             distances[src][node] = min(cost, distances[src][node]);
//             visited[lastNode][node]=1;
//             for (auto& nei : adj[node]) {
//                 if (visited[node][nei[0]] == 0) {
//                     pq.push({cost + nei[1], nei[0], node});
//                 }
//             }
//         }
//         return;
//     }
// };
