class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        unordered_map<string,int> dir={{"RIGHT",1},{"LEFT",-1},{"DOWN",n},{"UP",-n}};
        return solve(commands,0,dir);
    }
    
    int solve(vector<string>& commands,int index,unordered_map<string,int>& dir){
        if(index>=commands.size()){
            return 0;
        }

        int ans=0;
        ans+=dir[commands[index]]+solve(commands,index+1,dir);
        return ans;
    }
};