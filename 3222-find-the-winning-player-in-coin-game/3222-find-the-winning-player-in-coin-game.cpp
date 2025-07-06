class Solution {
public:
    string losingPlayer(int x, int y) {
        int turn=0;
        while(x>0 && y>3){
            x--;
            y-=4;
            turn=!turn;
        }
        if(turn==0){
            return "Bob";
        }
        return "Alice";
    }
};