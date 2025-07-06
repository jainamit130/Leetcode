class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<int> diff;
        for(int i=0;i<nums.size();i++){
            diff.push_back(target[i]-nums[i]);
        }

        long long ans=abs(diff[0]);
        int prev=abs(diff[0]);

        for(int i=1;i<diff.size();i++){
            if((diff[i]<0 && diff[i-1]<0) || (diff[i]>0 && diff[i-1]>0)){
                if(prev<abs(diff[i])){
                    ans+=abs(diff[i])-prev;
                }
            } else {
                ans+=abs(diff[i]);
            }
            prev=abs(diff[i]);
        }
        return ans;
    }
};


/*

3   5   1   2

4   6   2   4

1   1   1   2


diff
0   -1  -9  3   1   5   3   4   1
    i

ans=diff[0]=0;

if(diff[i]<0 && diff[i-1]<0 || diff[i]>0 && diff[i-1]>0 ){
    if(abs(diff[i-1])<abs(diff[i])){
        ans+=abs(diff[i])-abs(diff[i-1]);
    }
} else {
    ans+=diff[i];
}


*/