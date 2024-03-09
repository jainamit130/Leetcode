class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size());
        int initialMaxInCandies=0;
        for(int n:candies)
            initialMaxInCandies=max(initialMaxInCandies,n);

        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=initialMaxInCandies)
                result[i]=true;
        }
        return result;
    }
};