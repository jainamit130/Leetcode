class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        vector<vector<int>> cache(prices.size()+1,vector<int>(prices.size()+1,-1));
        return dp(0,prices,0,cache);
    }

    int dp(int index,vector<int>& prices,int freeFruits,vector<vector<int>>& cache){
        if(index>=prices.size())
            return 0;

        if(cache[index][freeFruits]!=-1)
            return cache[index][freeFruits];

        int a =INT_MAX, b = 0;
        b=prices[index]+dp(index+1,prices,index+1,cache);
        if(freeFruits>0)
            a=min(a,dp(index+1,prices,freeFruits-1,cache));
        return cache[index][freeFruits]=min(a,b);
    }
};


/*

38  23  27  32  47  45  48  24  39  26  37  42  24  45  27  26  15  16  26  6




*/