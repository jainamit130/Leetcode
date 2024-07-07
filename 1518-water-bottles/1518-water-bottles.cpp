class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int emptyBottles=numBottles;
        while(numExchange<=emptyBottles){
            emptyBottles-=numExchange;
            emptyBottles++;
            ans+=1;
        } 
        return ans;
    }
};