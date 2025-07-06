// class Solution {
// public:
//     int ans=0;
//     int longestIdealString(string s, int k) {
//         unordered_map<int,vector<int>> mp;
//         for(int i=0;i<s.length();i++){
//             mp[s[i]-'a'].push_back(i);
//         }
//         for(auto [a,b]:mp){
//             cout<<a<<" => ";
//             for(int i=0;i<b.size();i++){
//                 cout<<b[i]<<" ";
//             }
//             cout<<endl;
//         }
//         solve(s,0,mp,k,0);
//         return ans;
//     }

//     void solve(string s,int index,unordered_map<int,vector<int>>& mp,int k,int len){
//         if(index>=s.length()){
//             ans=max(ans,len);
//             return;
//         }

//         int pick=0,notPick=0;
//         int start=max(s[index]-k-'a',0);
//         int end=min(s[index]+k-'a',25);  
//         for(int i=start;i<=end;i++){
//             for(int j=0;j<mp[i].size();j++){
//                 if(index<mp[i][j]){
//                     solve(s,mp[i][j],mp,k,len+1);
//                 }
//             }   
//         }
//         solve(s,index+1,mp,k,len);
//         return;
//     }
// };

// class Solution {
// public:
//     int longestIdealString(string s, int k) {
//         vector<vector<int>> dp(s.length()+1,vector<int>(26));
//         for(int i=1;i<=s.length();i++){
//             dp[i]=dp[i-1];
//             for(int j=0;j<=25;j++){
//                 if(abs(s[i-1]-'a'-j)<=k){
//                     dp[i][j]=dp[i-1][j]+1;
//                 }
//             }
//         }
//         int ans=0;
//         for(int i=0;i<=25;i++)
//             ans=max(dp[s.length()][i],ans);
//         return ans;
//     }
// };


// class Solution {
// public:
//     int longestIdealString(string s, int k) {
//         int n = s.length();
//         int result = 1;
//         vector<int> t(n, 1);        
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < i; j++) {
//                 if(abs(s[j] - s[i]) <= k) {
//                     t[i] = max(t[i], t[j]+1);
//                 }
//             }
//             result = max(result, t[i]);
//         }
        
//         return result;
//     }
// };

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        
        vector<int> t(26, 0);
        
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            
            int curr    = s[i]-'a';
            int left    = max(0, curr-k);
            int right   = min(25, curr+k);

            int longest = 0;
            for(int j = left; j <= right; j++) {
                longest = max(longest, t[j]);
            }
            
            t[curr] = max(t[curr], longest+1);
            result = max(result, t[curr]);
        }
        
        return result;
        
    }
};

/*

a   c   f   g   b   d
                i
0   1   2   3   4   5
0   2   5   6   1   3

0 => 0 (0-2) 
2 => 1 (0-4)
5 => 2 (3-7)
6 => 3 (4-8)
1 => 4 (0-3)
3 => 5 (1-5)

*/