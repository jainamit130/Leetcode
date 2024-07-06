class Solution {
public:
    int passThePillow(int n, int time) {
        int round=time/(n-1);
        int sign=1;
        int start=1;
        if(round%2!=0){
            sign=0;
            start=n;
        }
        time=time%(n-1);
        while(time){
            if(sign){
                start++;
            } else {
                start--;
            }
            time--;
        }
        return start;
    }
};