class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int ans=0;
        int currSearch=1;
        int currTotal=0;
        int i=0;
        while(currSearch<=target){
            if(i>=coins.size() || currSearch<coins[i]) {
                currTotal+=currSearch;
                ans++;
            } else {
                currTotal+=coins[i];
                i++;
            }
            currSearch=currTotal+1;
        } 
        return ans;
    }
};

/*

1   2   4   8   12  15
                    i

ans = 3
currSearch = 16
currTotal= 15


1   2   4   5   7   10  19
                    i

currSearch = 32
currTotal = 31



1   2   4   8   10

1 -> 1
2 -> 2
3 -> 1  2
4 -> 4
5 -> 1  4
6 -> 4  2
7 -> 1  2   4
8 -> 8
9 -> 1  8
10 -> 10
11 -> 1 10
12 -> 2 10
13 -> 1 2   10
14 -> 4 10
15 -> 1 4   10
16 -> 2 4   10
17 -> 1 2   4   10
18 -> 8 10
19 ->  1    8   10

*/