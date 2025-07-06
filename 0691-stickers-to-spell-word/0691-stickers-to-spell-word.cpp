class Solution {
public:
    long long  helper(vector<string>& stickers,vector<vector<int>>&stickCount,unordered_map<string,long long >&dp,string t,unordered_map<char,int>&have){
        if(dp.find(t)!=dp.end())return dp[t];
        long long  res;
        have.size()!=0?res=1:res=0;
        string remT="";
        for(auto c:t){
            if(have.find(c)!=have.end() && have[c]>0)have[c]--;
            else remT+=c;
        }
        if(remT.size()>0){
            long long used =INT_MAX;
            for(int i=0;i<stickCount.size();i++){
                if(stickCount[i][remT[0]-'a']==0)continue;
                have.clear();
                for(auto c:stickers[i])have[c]++;
                used=min(used,helper(stickers,stickCount,dp,remT,have));
            }
            dp[remT]=used;
            res+=used;
        }
        return res;
}
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>>stickCount(stickers.size(),vector<int>(26,0));
        for(int i=0;i<stickers.size();i++){
            for(int j=0;j<stickers[i].size();j++){
                char c=stickers[i][j];
                stickCount[i][c-'a']++;
            }
        }
        unordered_map<char,int>have;
        have.clear();
        unordered_map<string,long long>dp;
        long long res= helper(stickers,stickCount,dp,target,have);
        return res>=INT_MAX?-1:(int)res;
    }
};

// class Solution {
// public:
//     int minStickers(vector<string>& stickers, string target) {
//         vector<unordered_map<char,int>> stickersLetterFreq(stickers.size());
//         for(int i=0;i<stickers.size();i++){
//             for(auto c:stickers[i])
//                 stickersLetterFreq[i][c]++;
//         }
//         unordered_set<int> visited;
//         unordered_set<string> depricated;
//         int ans=solve(stickersLetterFreq,stickers,target,0,visited,0,depricated);
//         if(ans==INT_MAX)
//             return -1;
//         return ans;
//     }

//     int solve(vector<unordered_map<char,int>>& stickersLetterFreq,vector<string>& stickers,string target,int index,unordered_set<int> visited,int currCount,unordered_set<string>& depricated){
//         if(index>=stickers.size())
//             return INT_MAX;

//         if(visited.size()==target.length())
//             return currCount;

//         if(depricated.size()==stickers.size())
//             return INT_MAX;

//         if(depricated.find(stickers[index])!=depricated.end())
//             return INT_MAX;

//         cout<<index<<" "<<" "<<stickers[index]<<" "<<currCount<<endl;
//         print(visited);
//         //Not the word
//         int flag=0;
//         vector<unordered_map<char,int>> stickersMapCopy=stickersLetterFreq;
//         vector<int> temp;
//         for(int i=0;i<target.size();i++){
//             if(visited.find(i)!=visited.end()) {
//                 continue;
//             } else {
//                 if(stickersMapCopy[index].find(target[i])!=stickersMapCopy[index].end()){
//                     cout<<i<<" "<<target[i]<<" "<<stickersMapCopy[index][target[i]]<<endl;
//                     visited.insert(i);
//                     temp.push_back(i);
//                     stickersMapCopy[index][target[i]]--;
//                     if(stickersMapCopy[index][target[i]]==0)
//                         stickersMapCopy[index].erase(target[i]);
//                     flag=1;
//                 }
//             }
//         }   
//         int ans=INT_MAX;
//         if(!flag) {
//             depricated.insert(stickers[index]);
//             ans=min(ans,solve(stickersLetterFreq,stickers,target,index+1,visited,currCount,depricated));
//         }
//         ans=min(ans,solve(stickersLetterFreq,stickers,target,0,visited,currCount+1,depricated));
//         while(temp.size()){
//             visited.erase(temp.back());
//             temp.pop_back();
//         }
//         depricated.clear();
//         cout<<"ans = "<<ans<<endl;
//         return ans;
//     }

//     void print(unordered_set<int> myset){
//         cout<<"Visited : ";
//         for (auto it = myset.begin(); it !=myset.end(); ++it)
//         cout << ' ' << *it;
//         cout<<endl;
//     }
// };