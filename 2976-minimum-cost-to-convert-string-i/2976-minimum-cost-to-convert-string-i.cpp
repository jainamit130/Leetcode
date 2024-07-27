// class Solution {
// public:
//     using ll =long long;
//     ll minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         vector<vector<ll>> distances(26,vector<ll>(26,INT_MAX));
//         for (int i = 0; i < original.size(); i++) {
//             distances[original[i]-'a'][changed[i]-'a']=min(distances[original[i]-'a'][changed[i]-'a'],(ll)cost[i]);
//         }    

//         for(int k=0;k<26;k++){
//             for(int i=0;i<26;i++){
//                 for(int j=0;j<26;j++){
//                     distances[i][j]=min(distances[i][j],distances[i][k]+distances[k][j]);
//                 }
//             }
//         }

//         long long ans=0;
//         for(int i=0;i<source.size();i++){
//             int src=source[i]-'a';
//             int dst=target[i]-'a';
//             if(src==dst)
//                 continue;
//             if(distances[src][dst]==INT_MAX)
//                 return -1;
//             ans+=distances[src][dst];
//         }   
//         return ans;
//     }
// };


class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {

        vector<vector<vector<int>>> adj(26);
        for (int i = 0; i < original.size(); i++) {
            adj[original[i]-'a'].push_back({changed[i]-'a', cost[i]});
        }

        long long ans = 0;
        vector<vector<int>> distances(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < target.size(); i++) {
            int src = source[i]-'a';
            int dst = target[i]-'a';
            if(src==dst){
                continue;
            }

            if (distances[src][dst] == INT_MAX) {
                solve(distances, src, dst, adj);
                if (distances[src][dst] == INT_MAX){
                    return -1;
                }
            }
            ans += distances[src][dst];
        }
        return ans;
    }

    void solve(vector<vector<int>>& distances, int& src,
               vector<vector<vector<int>>>& adj) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, src});
        while (!pq.empty()) {
            int node = pq.top()[1];
            int cost = pq.top()[0];
            pq.pop();
            distances[src][node] = min(cost, distances[src][node]);
            for (auto& nei : adj[node]) {
                if(distances[src][nei[0]]>(cost+nei[1]))
                    pq.push({cost + nei[1], nei[0]});
            }
        }
        return;
    }
};
