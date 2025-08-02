class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> mp1,mp2;
        map<int,int> totalMap;
        int n = basket1.size();
        for(int i=0;i<n;i++) {
            mp1[basket1[i]]++;
            mp2[basket2[i]]++;
            totalMap[basket1[i]]++;
            totalMap[basket2[i]]++;
        }
        long long ans = 0;
        vector<int> first,second;
        for(auto [cost,freq] : totalMap) {
            if(freq%2!=0) return -1;
            int count = mp1[cost]-mp2[cost];
            if(count<0) populateLack(cost,abs(count),first);
            else if(count>0) populateLack(cost,abs(count),second);
        }

        sort(first.begin(),first.end());
        sort(second.begin(),second.end());
        int minNum = totalMap.begin()->first;
        int i1=0,j1=first.size()-1;
        int i2=0,j2=second.size()-1;
        while(i1<=j1 && i2<=j2) {
            int min1 = 2*minNum;
            int min2 = min(first[i1],second[j2]);
            int min3 = min(first[j1],second[i2]);
            if(min1<=min2 && min1<=min3) {
                j1--; j2--;
            } else if(min2<=min1 && min2<=min3) {
                i1++; j2--;
            } else {
                i2++; j1--;
            }
            ans += min({min1,min2,min3});
        }
        return ans/2;
    }

    void populateLack(int cost,int count,vector<int>& arr) {
        while(count--) arr.push_back(cost);
    }
};



/*

1 -> 2
2 -> 4
3 -> 2
4 -> 2
5 -> 2


1 -> 3


1 -> 0
2 -> 2
3 -> 1
5 -> 1

4   4   1   5   2   3   2


4   5   6

1 -> 1
2 -> 2
3 -> 1
5 -> 1

5   1   1   1   3   2   2


1   1


5   5

3   4   4   4   4


3 -> 2
4 -> 4
5 -> 4


4   4


3   5   5   5   5


*/