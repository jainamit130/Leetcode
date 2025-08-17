class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> prob(n+1,0);
        prob[0]=1;
        double ans = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=maxPts;j++) {
                if(i-j>=0 && i-j<k) {
                    prob[i]+=prob[i-j]*(1/(double)maxPts);
                }
            }
            if(i>=k) ans+=prob[i];
        }
        return ans;
    }
};

/*

P(21) = P(16)*P(5) + ..... + P(11)*P(10)
P(n) = P(k-1)*(1/m) + P(k-2)*(1/m) . . . . . + P(n-m)*(1/m) 


Alice starts with 0 points

probability that the final number lies between k to n

ceil(21/10) = 3
ceil(17/10) = 2

7   10 -> 1
8   10,9 -> 2 
9   10,9,8 -> 3
10  10,9,8,7 -> 4

1   6   10
1   7   10,9
1   8   10,9,8
1   9   10,9,8,7
1   10   10,9,8,7,6

3 => numbers totalling to 17 - 21 
2 => numbers totalling to 17 - 21

ans = 0;

i from ceil(k/maxPts) to ceil(n/maxPts) 

ans += (2 - Probability of having i numbers totalling less than ceil(k/maxPts) - Probability of having i numbers totalling less than ceil(n/maxPts)+1)



10/10*10 + /10*10*10

*/