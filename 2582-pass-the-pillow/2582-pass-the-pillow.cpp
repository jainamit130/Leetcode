class Solution {
public:
    int passThePillow(int n, int time) {
        int round=time/(n-1);
        time=time%(n-1);
        int start=1;
        int ans=start+time;
        if(round%2!=0){
            start=n;
            ans=start-time;
        }
        return ans;
    }
};