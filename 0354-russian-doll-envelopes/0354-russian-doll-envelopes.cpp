class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](auto lhs,auto rhs){
            if(lhs[0]==rhs[0]){
                return lhs[1]>rhs[1];
            } 
            return lhs[0]<rhs[0];
        });

        // return findLis(envelopes);
        return findLisBS(envelopes);
    }

    int findLisBS(vector<vector<int>>& envelopes){
        int n=envelopes.size();
        vector<int> sorted;
        sorted.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            auto itr=lower_bound(sorted.begin(),sorted.end(),envelopes[i][1]);
            if(itr==sorted.end()){
                sorted.push_back(envelopes[i][1]);
            } else {
                int index=itr-sorted.begin();
                sorted[index]=envelopes[i][1];
            }
        }
        return sorted.size();
    }

    // int findLis(vector<vector<int>>& envelopes){
    //     int n=envelopes.size();
    //     vector<int> dp(n);
    //     dp[n-1]=1;
    //     int ans=1;
    //     for(int i=n-2;i>=0;i--){
    //         int subAns=1;
    //         for(int j=i+1;j<n;j++){
    //             if(envelopes[j][1]>envelopes[i][1]){
    //                 subAns=max(subAns,dp[j]+1);
    //             }
    //         }
    //         dp[i]=subAns;
    //         ans=max(ans,subAns);
    //     }
    //     return ans;
    // }

    
};


// class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         sort(envelopes.begin(),envelopes.end(),[](auto lhs,auto rhs){
//             if(lhs[0]==rhs[0]){
//                 return lhs[1]<rhs[1];
//             } 
//             return lhs[0]>rhs[0];
//         });
//         unordered_map<int,unordered_map<int,vector<int>>> cache;
//         return solve(envelopes,0,INT_MAX,INT_MAX,cache);
//     }

//     int solve(vector<vector<int>>& envelopes,int index,int hMax,int wMax,unordered_map<int,unordered_map<int,vector<int>>>& cache){
//         if(index>=envelopes.size()){
//             return 0;
//         }

//         if(cache.find(hMax)!=cache.end() && cache[hMax].find(wMax)!=cache[hMax].end() && cache[hMax][wMax][index]!=-1){
//             return cache[hMax][wMax][index];
//         }

//         if(cache[hMax][wMax].size()==0){
//             cache[hMax][wMax].resize(envelopes.size()+1,-1);
//         }
//         int ans=0;
//         if(envelopes[index][0]<hMax && envelopes[index][1]<wMax)
//             ans=max(ans,1+solve(envelopes,index+1,min(hMax,envelopes[index][0]),min(wMax,envelopes[index][1]),cache));
//         ans=max(ans,solve(envelopes,index+1,hMax,wMax,cache));
//         return cache[hMax][wMax][index]=ans;
//     }
// };



/*
5   4
6   4
6   7


6   7
6   4
5   4


*/