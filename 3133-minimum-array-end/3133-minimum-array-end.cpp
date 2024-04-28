class Solution {
public:
    using ll = long long;
    ll minEnd(int n, int x){
        ll  num = x , one = 1;
        vector<int> unsetBits;
        for(int bit = 0 ; bit < 63 ; bit++){
            if(num >> bit & one ^ one){
                unsetBits.push_back(bit);
            }
        }
        int m = unsetBits.size();
        for(ll mask = 0 ; mask < (one << m) ; mask++){
            if(--n == 0){
                for(int index = 0 ; index < m ; index++){
                    if(mask >> index & one){
                        num |= one << unsetBits[index];
                    }
                }
                return num;
            }
        }
        return num;
    }
};
