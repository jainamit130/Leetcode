class Solution {
public:
    vector<int> cache;
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        cache.resize(nums.size()+1,-1);
        return solve(nums,0);
    }

    int solve(vector<int>& vec,int index) {
        if(index>=vec.size())  return 0;
        if(cache[index]!=-1) return cache[index];
        int ans = 0;
        int i = index;
        int val = vec[i];
        int points = vec[i];
        i++;
        while(i<vec.size() && vec[i]==vec[i-1]) {
            points+=vec[i];
            i++;
        }
        if(val+1==vec[i]) {
            i++;
            while(i<vec.size() && vec[i]==vec[i-1]) i++;
        }
        ans = max(ans,points+solve(vec,i));
        i=index;
        i++;
        while(i<vec.size() && vec[i]==vec[i-1]) i++;
        ans = max(ans,solve(vec,i));
        return cache[index]=ans;
    }
};

/*

27 + 15 + 14 + 4 + 


*/