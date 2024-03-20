class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        visited.insert(0);
        return dfs(0,rooms,visited);
    }

    bool dfs(int index,vector<vector<int>> rooms,unordered_set<int>& visited){
        if(index>=rooms.size() && visited.size()<rooms.size()){
            return false;
        }

        if(visited.size()==rooms.size())
            return true;

        bool ans=false;
        for(int i=0;i<rooms[index].size();i++){
            if(visited.find(rooms[index][i])!=visited.end())
                continue;
            visited.insert(rooms[index][i]);
            ans= ans || dfs(rooms[index][i],rooms,visited);
        }
        return ans;
    }
};