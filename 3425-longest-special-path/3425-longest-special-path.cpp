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
        visited[0]=1;
        mp[nums[0]]=0;
        path.push_back(0);
        solve(adj,nums,visited,0,0,-1,path,mp);
        return {maxLen,minNodes};
    }

    void solve(vector<vector<vector<int>>>& adj,vector<int>& nums,vector<int>& visited,int node,int length,int lastSeen,vector<int>& path,unordered_map<int,int>& mp) {
        // cout<<"Node: "<<node<<endl;
        // cout<<"Last seen: "<<lastSeen<<endl;
        // cout<<"Path: ";
        // for(auto p:path) {
        //     cout<<p<<" , ";
        // }
        // cout<<endl<<"Map: ";
        // for(auto [val,ind]:mp) {
        //     cout<<val<<" -> "<<ind<<"; ";
        // }
        // cout<<endl;
        // cout<<"MaxLen : "<<maxLen<<endl;
        // cout<<"MinNodes : "<<minNodes<<endl;
        // cout<<endl;
        for(int i=0;i<adj[node].size();i++) {
            int neigh = adj[node][i][0];
            int currLength = length+adj[node][i][1];
            if(visited[neigh]==1) continue;
            visited[neigh]=1;
            int tempMp = -1;
            path.push_back(currLength);
            int index = lastSeen;
            if(mp.find(nums[neigh])!=mp.end()) {
                if(mp[nums[neigh]]>lastSeen)
                    index = mp[nums[neigh]];
                tempMp = mp[nums[neigh]];
            } 
            int lastLength = path[index+1];
            int subLen = currLength-lastLength;
            int subNodes = path.size()-1-index;
            if(maxLen<subLen) {
                maxLen = subLen;
                minNodes = subNodes; 
            } else if(maxLen==subLen) {
                minNodes = min(subNodes,minNodes);
            }
            mp[nums[neigh]]=path.size()-1;
            solve(adj,nums,visited,neigh,length+adj[node][i][1],index,path,mp);
            if(tempMp!=-1){
                mp[nums[neigh]]=tempMp;
            } else {
                mp.erase(nums[neigh]);
            }
            path.pop_back();
        }
    }
};

/*

1   0   3




*/