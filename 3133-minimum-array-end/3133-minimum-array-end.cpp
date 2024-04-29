// class Solution {
// public:
//     using ll = long long;
//     ll minEnd(int n, int x){
//         ll  num = x , one = 1;
//         vector<int> unsetBits;
//         for(int bit = 0 ; bit < 63 ; bit++){
//             if(num >> bit & one ^ one){
//                 unsetBits.push_back(bit);
//             }
//         }
//         for(int i=0;i<unsetBits.size();i++)
//             cout<<unsetBits[i]<<endl;
//         int m = unsetBits.size();
//         for(ll mask = 0 ; mask < (one << m) ; mask++){
//             if(--n == 0){
//                 for(int index = 0 ; index < m ; index++){
//                     if(mask >> index & one){
//                         num |= one << unsetBits[index];
//                     }
//                 }
//                 return num;
//             }
//         }
//         return num;
//     }
// };


class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        if(n==0)
            return x;
        vector<int> unsetBits(64,0);
        long long t=1;
        for(int i=63;i>=0;i--){
            if((t<<(63-i)) & x){
                unsetBits[i]=1;
            }
        }
        vector<int> unsetBits1=unsetBits;
        long long numberOfZeros=1;
        while(n){
            unsetBits1=unsetBits;
            int k=63;
           for(int i=63;i>=0;i--){
                if(unsetBits1[i]==0){
                    unsetBits1[i]=unsetBits1[i]|((numberOfZeros>>(63-k)) & 1);
                    // cout<<i<<" "<<k<<" "<<unsetBits1[i]<<endl;
                    k--;
                }
           }
           numberOfZeros++;
            n--;
        }
        long long ans=0;
        for(int i=0;i<64;i++){
            ans= (ans<<1) | unsetBits1[i];
        }
        return ans;
    }
};