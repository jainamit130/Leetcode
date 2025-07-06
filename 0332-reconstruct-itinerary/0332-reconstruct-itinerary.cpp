class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        
        for (auto& entry : adj) {
            sort(entry.second.begin(), entry.second.end());
        }

        vector<string> itinerary;
        dfs("JFK", adj, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

private:
    void dfs(string node, unordered_map<string, vector<string>>& adj, vector<string>& itinerary) {
        auto& dests = adj[node];
        while (!dests.empty()) {
            string next = dests.front();
            dests.erase(dests.begin());
            dfs(next, adj, itinerary);
        }
        itinerary.push_back(node);
    }
};
