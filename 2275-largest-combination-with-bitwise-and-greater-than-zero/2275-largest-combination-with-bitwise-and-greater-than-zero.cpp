class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> freq(25);
        for(auto c:candidates){
            int bit = 0;
            while(c){
                if(c&1){
                    freq[bit]++;
                }
                bit++;
                c=c>>1;
            }
        }
        int ans = 0;
        for(auto f:freq){
            ans=max(ans,f);
        }
        return ans;
    }
};


/*

And operation always is monotonically decreasing


71 - 1  0   0   0   1   1   1   
62 -    1   1   1   1   1   0
24 -        1   1   0   0   0   
17 -        1   0   0   0   1
16 -        1   0   0   0   0
14 -            1   1   1   0
12 -            1   1   0   0


*/