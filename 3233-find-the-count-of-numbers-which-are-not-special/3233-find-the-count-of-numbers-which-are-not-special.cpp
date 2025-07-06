class Solution {
public:
    int nonSpecialCount(int l, int r) {
       //Seive of Erosthenes
       vector<bool> isPrime((int)sqrt(r)+1,true);
       isPrime[1]=false;
       for(long i=2;i*i<=r;i++){
            for(long j=i*i;j*j<=r;j+=i){
                isPrime[j]=false;
            }
       } 
        long long ans=r-l+1;
       for(int i=ceil(sqrt(l));i<=sqrt(r);i++){
            if(isPrime[i]){
                ans--;
            }
       }
       return ans;
    }
};