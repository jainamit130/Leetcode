class Solution {
public:
    int findIntegers(int n) {
        vector<int> fib(31);
        // Populate the fibonacci
        fib[0]=1;
        fib[1]=2;
        for(int i=2;i<31;i++){
            fib[i]=fib[i-1]+fib[i-2];
        }

        int ans = 0;
        int last = 0;
        int k=30;
        while(k>=0){
            if(n&(1<<k)){
                ans+=fib[k];
                if(last==1){
                    return ans;
                }
                last=1;
            } else {
                last=0;
            }
            k--;
        }
        return ans+1;
    }
};