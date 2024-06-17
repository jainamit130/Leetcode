class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a=0;a<=c;a++){
            int t=c-(a*a);
            if(t<0)
                break;
            int b=sqrt(t);
            if((a*a+b*b)==c)
                return true;
        }
        return false;
    }
};