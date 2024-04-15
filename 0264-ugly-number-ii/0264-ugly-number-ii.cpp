// #Approach 1
// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         set<long> st;
//         st.insert(1);
//         long num;
//         for(int i=1;i<=n;i++){
//             num = *st.begin();
//             st.erase(num);
//             st.insert(num*2);
//             st.insert(num*3);
//             st.insert(num*5);
//         }
//         return num;
//     }
// };

// #Approach 2
class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<long long> visited;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        pq.push(1);
        long long top=1;
        int count=0;
        while(count!=n){
            top=pq.top();
            pq.pop();
            if(visited.find(top)!=visited.end())
                continue;
            else {
                count++;
                visited.insert(top);
            }
            pq.push(top*2);
            pq.push(top*3);
            pq.push(top*5);
        }
        return top;
    }
};

// #Approach 3
// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         vector<int> dp(n);
//         dp[0]=1;
//         int p2=0,p3=0,p5=0;
//         for(int i=1;i<n;i++){
//             dp[i]=min(dp[p2]*2,min(dp[p3]*3,dp[p5]*5));
//             if(dp[p2]*2==dp[i]) p2++;
//             if(dp[p3]*3==dp[i]) p3++;
//             if(dp[p5]*5==dp[i]) p5++;
//         }
//         return dp[n-1];
//     }
// };


/*
dp
0   1   2   3   4   5   6   7   8   9   10    
1   2   3   4   5   6   8   9   10  12  15      
                        p2
                    p3
            p5

*/