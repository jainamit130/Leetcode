class Solution {
public:
    int passThePillow(int n, int time) {
        int round=time/(n-1);
        time=time%(n-1);
        if(round%2!=0){
            return n-time;
        }
        return n+time;
    }
};