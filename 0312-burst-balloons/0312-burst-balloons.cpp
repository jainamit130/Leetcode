class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> cache(nums.size()+1,vector<int>(nums.size(),-1));
        return solve(nums,0,nums.size()-1,cache);
    }

    int solve(vector<int>& nums,int L,int R,vector<vector<int>>& cache){
        if(L>R){
            return 0;
        }

        if(cache[L][R]!=-1){
            return cache[L][R];
        }

        int ans=INT_MIN;
        for(int i=L;i<=R;i++){
            int leftVal=1;
            if(L-1>=0){
                leftVal=nums[L-1];
            }

            int rightVal=1;
            if(R+1<nums.size()){
                rightVal=nums[R+1];
            }
            ans=max(ans,leftVal*nums[i]*rightVal+solve(nums,L,i-1,cache)+solve(nums,i+1,R,cache));
        }
        return cache[L][R]=ans;
    }
};

// class Solution {
// public:
//     int maxCoins(vector<int>& nums) {
//         unordered_set<int> visited;
//         vector<pair<int,int>> leftRight(nums.size(),{-1,-1});
//         return solve(nums,visited,leftRight);
//     }

//     int solve(vector<int>& nums,unordered_set<int>& visited,vector<pair<int,int>>& leftRight){
//         if(visited.size()==nums.size()){
//             return 0;
//         }

//         int ans=INT_MIN;
//         for(int i=0;i<nums.size();i++){
//             if(visited.find(i)!=visited.end()){
//                 continue;
//             }

//             visited.insert(i);
//             int leftVal=1;
//             int rightVal=1;
//             int j=i-1;
//             vector<pair<int,int>> temp=leftRight;
//             if(j>=0){
//                 while(visited.find(j)!=visited.end() && j!=-1){
//                     leftRight[j].second=i;
//                     j=leftRight[j].first;
//                 }
//                 if(j!=-1)
//                     leftVal=nums[j];
//             }
//             int k=i+1;
//             if(k<nums.size()){
//                 while(visited.find(k)!=visited.end() && k!=nums.size()){
//                     leftRight[k].first=i;
//                     k=leftRight[k].second;
//                 }
//                 if(k!=nums.size())
//                     rightVal=nums[k];
//             }

//             leftRight[i]={j,k};
//             ans=max(ans,(leftVal*nums[i]*rightVal)+solve(nums,visited,leftRight));
//             leftRight=temp;
//             visited.erase(i);
//         }
//         return ans;
//     }
// };

/*

3   1   5   4   8

0   1     2     3    4

3   0,1   5     4    8
3   0,3   0,3   4    8
3   0,3   0,4   0,4  8


*/