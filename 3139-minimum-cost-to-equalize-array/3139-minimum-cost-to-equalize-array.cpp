class Solution {
public:
    long long minNum=0;
    long long maxNum=0;
    long long sum = 0;
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        minNum = *min_element(nums.begin(), nums.end()); 
        maxNum = *max_element(nums.begin(), nums.end());
        sum = accumulate(nums.begin(),nums.end(),sum);
        long long ans=1e18;
        long long mod = 1e9+7; 
        for(int i=maxNum;i<=2*maxNum;i++){
            ans=min(ans,solve(nums,cost1,cost2,i));
        }
        return ans%mod;
    }

    long long solve(vector<int>& nums,int cost1,int cost2, int target){
        long long maxDiff=target-minNum;
        long long total=nums.size()*target-sum;
        
        if(2*cost1<=cost2) return total*cost1;
        
        long long remainingDiff = total - maxDiff;
        if((total/2)<maxDiff) return (maxDiff-remainingDiff)*cost1+remainingDiff*cost2;

        if(total%2==0) return (total/2)*cost2;
        else return (total/2)*cost2+cost1; 
    }
};


// class Solution {
// public:
//     int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
//         int n = nums.size();

//         int maxNum = *max_element(nums.begin(), nums.end());

//         priority_queue<int, vector<int>, greater<int>> pq;

//         for (int num : nums) {
//             if (num < maxNum) {
//                 pq.push(num);
//             }
//         }

//         int ans=0;
//         while (!pq.empty()) {
//             int a = pq.top();
//             pq.pop();
//             int t1=cost1;
//             a++;
//             int t2=INT_MAX;
//             if(!pq.empty() && cost2<=cost1*2){
//                 int b=pq.top();
//                 pq.pop();
//                 t2=cost2;
//                 b++;
//                 if(b<maxNum)
//                     pq.push(b);
//             }
//             ans+=min(t1,t2);
//             if(a<maxNum)
//                 pq.push(a);
//         }

//         return ans % 1000000007;
//     }
// };

/*
1   14  14  15

t = 15
mn = 1
sum = 44

i => 15 - 1030

fn
sum = 4*15 -44 = 16
mx = 15 - 1 = 14
pairing = min(8,2) = 2
cost = min(2,8) = 2
cost = 2 + 2*(16-2*2) = 2 + 2*8 = 2 + 16 = 18 


*/