class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        vector<long long> opsPrefix(1);
        opsPrefix.push_back(2);
        long long n = 12;
        int index = 1;
        while(n<INT_MAX) {
            // index + 1 operations on pairs
            // pairs = (n)/2
            opsPrefix.push_back(opsPrefix.back() + (index+1)*(n/2));
            index++;
            n*=4;
        }
        // for(auto t:opsPrefix) cout<<t<<endl;
        long long ans = 0;
        for(auto q:queries) {
            int start = q[0], end = q[1];
            int index1 = log2(start)/2, index2 = log2(end)/2;
            ans += opsPrefix[index2] - opsPrefix[index1];
            long long base1 = 1LL << (2*index1); 
            long long base2 = 1LL << (2*index2); 
            long long subOps1 = ((start - base1) / 2) * (index1+1);
            long long subOps2 = ((end   - base2 + 1) / 2) * (index2+1);
            ans += subOps2 - subOps1;
        }
        return ans;
    }
};

/*
259/4 = 64  1

... 250 251 252 253 254 255 256 257 258 259   
    63  63  63  64  64  64  64  65  65  65


1   1   1   2   2   2   2   2   2   2   2   2   2   2   2   3   3   3   3   3   3   3   3   3
1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24

0   0   0   0   0
0   0   0   0   1
0   0   0   1   0
0   0   0   1   1

0   0   1   0   0
0   0   1   0   1
0   0   1   1   0
0   0   1   1   1 
0   1   0   0   0
0   1   0   0   1
0   1   0   1   0
0   1   0   1   1
0   1   1   0   0
0   1   1   0   1
0   1   1   1   0
0   1   1   1   1

1   0   0   0   0
1   0   0   0   1
1   0   0   1   0
1   0   0   1   1
1   0   1   0   0
1   0   1   0   1
1   0   1   1   0
1   0   1   1   1


    1   4   16  64  256
    3   12  48  192 384
    2   12  72  384 1920
0   2   14  86  470 2390



*/