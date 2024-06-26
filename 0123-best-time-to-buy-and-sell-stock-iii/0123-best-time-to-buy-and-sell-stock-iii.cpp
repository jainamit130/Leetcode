class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> cache(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,false,2,cache);
    }

    int solve(vector<int>& prices,int index,bool isBought,int transactions,vector<vector<vector<int>>>& cache){
        if(index>=prices.size() || transactions<=0){
            return 0;
        }

        if(cache[index][isBought][transactions]!=-1){
            return cache[index][isBought][transactions];
        }

        int ans=INT_MIN;
        if(isBought){
            ans=max(ans,prices[index]+solve(prices,index+1,false,transactions-1,cache));
        } else {
            ans=max(ans,-prices[index]+solve(prices,index+1,true,transactions,cache));
        }
        ans=max(ans,solve(prices,index+1,isBought,transactions,cache));
        return cache[index][isBought][transactions]=ans;

    }
};