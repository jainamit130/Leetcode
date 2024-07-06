class Solution {
public:
    int passThePillow(int n, int time) {
        bool signPositive=true;
        int i=1;
        while(time){
            if(i==n+1){
                i=n-1;
                signPositive=false;
            } else if(i==0){
                i=2;
                signPositive=true;
            }
            if(signPositive){
                i++;
            } else {
                i--;
            }
            time--;
        }
        return i;
    }
};