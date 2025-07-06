class Solution {
public:
    int maxLen = 0;
    int minNodes = 1;
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }

        vector<int> visited(n);
        vector<int> path;
        unordered_map<int,int> mp;
        path.push_back(0);
        mp[nums[0]] = 0;
        visited[0]=1;
        solve(adj,nums,visited,0,0,-1,path,mp);
        return {maxLen,minNodes};
    }

    void solve(vector<vector<vector<int>>>& adj,vector<int>& nums,vector<int>& visited,int node,int length,int lastSeen,vector<int>& path,unordered_map<int,int>& mp) {
        for(int i=0;i<adj[node].size();i++) {
            int neigh = adj[node][i][0];
            int currLength = length+adj[node][i][1];
            if(visited[neigh]==1) continue;
            visited[neigh]=1;
            path.push_back(currLength);
            int index = lastSeen;
            int tempMp = -1;
            if(mp.find(nums[neigh])!=mp.end()) {
                if(mp[nums[neigh]]>lastSeen) {
                    index=mp[nums[neigh]];
                }
                tempMp = mp[nums[neigh]];
            }
            int lastLength = path[index+1];
            int subLen = currLength-lastLength;
            int subNodes = path.size()-index-1;
            if(maxLen<subLen) {
                maxLen = subLen;
                minNodes=subNodes;
            } else if(maxLen==subLen) {
                minNodes=min(minNodes,subNodes);
            }

            mp[nums[neigh]] = path.size()-1;
            solve(adj,nums,visited,neigh,length+adj[node][i][1],index,path,mp);
            if(tempMp!=-1) {
                mp[nums[neigh]]=tempMp;
            } else {
                mp.erase(nums[neigh]);
            }
            path.pop_back();
        }
    }
};


/*
      0    1    2   
path: 0 -> 1 -> 2
      0    2    5 
map: kay as val -> index on path
length => running length
lastSeen
visited


*/