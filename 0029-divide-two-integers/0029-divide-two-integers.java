class Solution {
    public int divide(int dividend, int divisor) {
        double q = dividend/(double)divisor;
        int sign = (q<0) ? -1 : 1;
        if(sign==-1) q = Math.max(-2e31,q);
        else q = Math.min(2e31-1,q);
        if(q==-2147483648) return (int)q;
        q = Math.abs(q);
        return (int)(Math.floor(q)*sign);        
    }
}