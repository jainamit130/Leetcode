class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        
        unordered_map<string,vector<pair<string,double>>> mp1,mp2;

        for(int i=0;i<pairs1.size();i++) {
            mp1[pairs1[i][0]].push_back({pairs1[i][1],rates1[i]});
            mp1[pairs1[i][1]].push_back({pairs1[i][0],1/rates1[i]});
        }

        for(int i=0;i<pairs2.size();i++) {
            mp2[pairs2[i][0]].push_back({pairs2[i][1],rates2[i]});
            mp2[pairs2[i][1]].push_back({pairs2[i][0],1/rates2[i]});
        }

        unordered_map<string,double> firstDayRates;
        firstDayRates[initialCurrency] = 1.0;
        dfs(initialCurrency,mp1,firstDayRates);

        double ans = 1.0;
        for(auto [currency,firstDayRate]:firstDayRates) {
            double secondDayRate = bfs(currency,initialCurrency,mp2);
            ans = max(ans,firstDayRate*secondDayRate);
        }

        return ans;
    }

    double bfs(string src,string dst,unordered_map<string,vector<pair<string,double>>>& adj) {
        queue<pair<string,double>> q;
        unordered_set<string> visited;

        q.push({src,1.0});
        
        while(!q.empty()) {
            auto [node,rate] = q.front();
            q.pop();

            if(visited.count(node)) continue;
            visited.insert(node);

            if(node == dst) return rate;

            for(auto [neighbor,neighborRate]:adj[node]) {
                if(!visited.count(neighbor)) {
                    q.push({neighbor,rate*neighborRate});
                }
            }
        }
        return 0.0;
    }

    void dfs(string node,unordered_map<string,vector<pair<string,double>>>& adj,unordered_map<string,double>& firstDayRates) {
        for(auto [neighbor,rate]:adj[node]) {
            if(!firstDayRates.count(neighbor)) {
                firstDayRates[neighbor] = firstDayRates[node] * rate;
                dfs(neighbor,adj,firstDayRates);
            }
        }
    }
};


/*

Map
EUR = 1.0
USD = 2.0
JPY = 6.0

1st Graph -> we fix the source and changed that targets (DFS)
2nd Graph -> we fix the src (all the other currencies) and change the dst (intit currency) (BFS)


*/