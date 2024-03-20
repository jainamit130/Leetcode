class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size());
        visited[0]=1;
        dfs(0,rooms,visited);
        for(int i = 0 ;i < rooms.size() ;++i){
            if(!visited[i]) return  0;
        }
        return 1;
    }

    void dfs(int index,vector<vector<int>> rooms,vector<int>& visited){
        if(index>=rooms.size()){
            return;
        }
        for(int i=0;i<rooms[index].size();i++){
            if(visited[rooms[index][i]])
                continue;
            visited[rooms[index][i]]=1;
            dfs(rooms[index][i],rooms,visited);
        }
        return;
    }
};