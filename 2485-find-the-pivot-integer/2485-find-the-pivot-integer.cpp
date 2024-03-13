class Solution {
public:
    int pivotInteger(int n) {
        int t=n*(n+1)/2;
        for(int i=n/2;i<=n;i++){
            if(i==sqrt(t))
                return i;
        }
        return -1;
    }
};