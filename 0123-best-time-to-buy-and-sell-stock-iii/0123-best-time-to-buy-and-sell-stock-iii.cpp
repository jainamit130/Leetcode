class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return solve(prices,0,0,false,2);
    }

    int solve(vector<int>& prices,int index,int currProfit,bool isBought,int transactions){
        if(index>=prices.size()){
            return currProfit;
        }

        if(transactions<0){
            return INT_MIN;
        }

        if(transactions==0 && !isBought){
            return currProfit;
        }

        int ans=0;
        if(isBought){
            ans=max(ans,max(currProfit,solve(prices,index+1,currProfit+prices[index],false,transactions-1)));
        } else {
            ans=max(ans,max(currProfit,solve(prices,index+1,currProfit-prices[index],true,transactions)));
        }
        ans=max(ans,max(currProfit,solve(prices,index+1,currProfit,isBought,transactions)));
        return ans;

    }
};