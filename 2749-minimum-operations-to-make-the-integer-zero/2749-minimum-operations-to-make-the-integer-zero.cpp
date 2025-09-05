class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t = 1;
        while((num1-t*1LL*num2)>0) {
            if(t>=__builtin_popcountll(num1-t*1ll*num2) && t<=(num1-t*1ll*num2)) return t;
            t++;
        }
        return -1;
    }
};