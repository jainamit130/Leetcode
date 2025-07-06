class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
    
    bool isprime[right+1];
    fill(isprime, isprime+right+1, true);
    isprime[0]=isprime[1]=false;
    
    for(int i=2;i<=right;i++){
        if(!isprime[i]) continue;
        for(long long j=1LL*i*i;j<=right;j+=i){
            isprime[j] = false;
        }
    }

    int l=-1, r=-1, prev=-1;
    for(int i=left; i<=right; i++){
        if(!isprime[i]) continue;
        if(l==-1) l = i;
        else if(r==-1){
            r = i;
        }
        else if(i-prev < r-l){
            l=prev;
            r=i;
        }
        prev = i;
    }

    if(r==-1) return {-1, -1};
    else return {l, r};
}
};