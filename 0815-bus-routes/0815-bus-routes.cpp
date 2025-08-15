class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<routes.size();i++) {
            for(int j=0;j<routes[i].size();j++) {
                mp[routes[i][j]].push_back(i);    
            }
        }

        queue<int> q;
        q.push(source);
        int level = 0;
        unordered_set<int> visited,indexSt;
        visited.insert(source);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int bus = q.front();
                q.pop();
                if(bus==target) return level;
                for(int i=0;i<mp[bus].size();i++) {
                    if(indexSt.find(mp[bus][i])!=indexSt.end()) continue;
                    indexSt.insert(mp[bus][i]);
                    for(int j=0;j<routes[mp[bus][i]].size();j++) {
                        if(visited.find(routes[mp[bus][i]][j])==visited.end()) {
                            visited.insert(routes[mp[bus][i]][j]);
                            q.push(routes[mp[bus][i]][j]);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};


/*


1->0
2->0
7->0,1
3->1
6->1

*/