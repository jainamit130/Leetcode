class Union {
    public:
        vector<int> parent;
        vector<int> rank;
        unordered_map<int,set<int>> online;

        Union(int n) {
            parent.resize(n);
            rank.resize(n);
            for(int i=0;i<n;i++) {
                parent[i]=i;
                set<int> st;
                st.insert(i);
                online[i] = st;
            }
        }

        int findParent(int n) {
            while(n!=parent[n]) n = parent[parent[n]];
            return n;
        }

        void merge(int n1,int n2) {
            int p1 = findParent(n1);
            int p2 = findParent(n2);
            if(p1==p2) return;
            if(rank[p1]>=rank[p2]) {
                parent[p2]=p1;
                rank[p1]++;
                online[p1].insert(online[p2].begin(),online[p2].end());
            } else {
                parent[p1]=p2;
                rank[p2]++;
                online[p2].insert(online[p1].begin(),online[p1].end());
            }
            return;
        }

        void turnOffline(int n) {
            int p = findParent(n);
            online[p].erase(n);
        }

        int performMaintenance(int n) {
            int p = findParent(n);
            if(online[p].empty()) return -1;
            if(online[p].count(n)) return n;
            return *online[p].begin();
        } 
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        Union root(c+1);
        for(int i=0;i<connections.size();i++) root.merge(connections[i][0],connections[i][1]);
        vector<int> ans;
        for(int i=0;i<queries.size();i++) {
            int node = queries[i][1];
            if(queries[i][0]==1) ans.push_back(root.performMaintenance(node));
            else root.turnOffline(node);
        }
        return ans;
    }
};


/*


DSU => iterate connections array and populate dsu
unordered_map<int,set<int>> => merge function contains logic for unioning the 2 sets into parent key in map based on rank



*/