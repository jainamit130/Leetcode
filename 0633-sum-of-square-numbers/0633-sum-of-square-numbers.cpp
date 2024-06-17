class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a=0;a<=c;a++){
            int t=c-((long long)a*a);
            if(t<0)
                break;
            int b=sqrt(t);
            if(((long long)a*a+(long long)b*b)==c)
                return true;
        }
        return false;
    }
};