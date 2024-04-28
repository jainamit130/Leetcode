class Solution {
public:
    long long minEnd(int n, int x) {
        n--;long long ans=x;long long temp=1;
        for(int i=0;i<=26 && n>0;i++){
            long long t=temp<<i;
            if(!(x&t)){
                ans=x|t;
                n--;
            }
        }
        return ans;
    }
};


/*

001
011
101
1001

*/