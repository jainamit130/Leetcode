class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xors = 0;
        for(auto n:nums) {
            xors^=n;
        }

        int index = 0;
        while(xors) {
            if(xors&1) break;
            index++;
            xors=xors>>1;
        }

        int a=0,b=0;
        for(auto n:nums) {
            if((n>>index)&1) a^=n;
            else b^=n;
        }
        return {a,b};
    }
};



/*
1   1   2   2   3   5


0   0   0   1
0   0   0   1
0   0   1   0
0   0   1   0
0   0   1   1
0   1   0   1
--------------
0   1   1   0





*/