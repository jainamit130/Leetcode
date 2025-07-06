class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end());
        long long ans = 0;
        int n = pizzas.size();
        int oddDaysCount = ceil(n/(double)8);
        int evenDaysCount = (n/4)-oddDaysCount;
        while(oddDaysCount--) {
            ans += 1LL*pizzas.back();
            pizzas.pop_back();
        }

        while(evenDaysCount--) {
            pizzas.pop_back();
            ans += 1LL*pizzas.back();
            pizzas.pop_back();
        }
        return ans;
    }
};

/*

3,4,2,4,2,4,2,2,4,5,3,2,1,2,1,1

1   1   1   2   2   2   2   2   2   3   3   4   4   4   4   5
1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16

2 odd 
2 even

*/