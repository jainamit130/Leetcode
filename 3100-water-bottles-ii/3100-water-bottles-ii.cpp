class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles=numBottles;
        int fullBottles=0;
        int ans=numBottles;
        while(numExchange<=emptyBottles){
            while(emptyBottles>=numExchange){
                emptyBottles-=numExchange;
                fullBottles+=1;
                numExchange+=1;
            }
            ans+=fullBottles;
            int t=fullBottles;
            fullBottles=0;
            emptyBottles+=t;    
        }
        return ans;
    }
};