class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> mp;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        vector<vector<int>> cache(stones.size()+1,vector<int>(stones.size()+1,-1));
        return solve(stones,0,0,mp,cache);
    }

    bool solve(vector<int>& stones,int index,int lastJump,unordered_map<int,int>& mp,vector<vector<int>>& cache){
        if(index>=stones.size() || index<0){
            return false;
        }

        if(index==stones.size()-1){
            return true;
        }

        if(cache[index][lastJump]!=-1){
            return cache[index][lastJump];
        }

        bool ans=false;
        if(mp.find(stones[index]+lastJump-1)!=mp.end() && mp[stones[index]+lastJump-1]>index)
            ans=ans||solve(stones,mp[stones[index]+lastJump-1],lastJump-1,mp,cache);
        if(mp.find(stones[index]+lastJump)!=mp.end() && mp[stones[index]+lastJump]>index)
            ans=ans||solve(stones,mp[stones[index]+lastJump],lastJump,mp,cache);
        if(mp.find(stones[index]+lastJump+1)!=mp.end() && mp[stones[index]+lastJump+1]>index)
            ans=ans||solve(stones,mp[stones[index]+lastJump+1],lastJump+1,mp,cache);
        return cache[index][lastJump]=ans;        
    }
};


/*

0   1   3   5   6   8   12  17







*/