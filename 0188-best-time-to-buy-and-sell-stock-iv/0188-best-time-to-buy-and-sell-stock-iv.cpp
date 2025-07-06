class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> cache(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(k,true,prices,0,cache);
    }

    int solve(int k,int isBuy,vector<int>& prices,int index,vector<vector<vector<int>>>& cache){
        if(index>=prices.size() || k<=0){
            return 0;
        }

        if(cache[index][isBuy][k]!=-1){
            return cache[index][isBuy][k];
        }
        
        cache[index][isBuy][k]=0;

        if(isBuy){
            //buy and skip
            cache[index][isBuy][k]=max(-prices[index]+solve(k,false,prices,index+1,cache),solve(k,true,prices,index+1,cache));
        } else {
            //sell and skip
            cache[index][isBuy][k]=max(prices[index]+solve(k-1,true,prices,index+1,cache),solve(k,false,prices,index+1,cache));
        }
        return cache[index][isBuy][k];
    }
};