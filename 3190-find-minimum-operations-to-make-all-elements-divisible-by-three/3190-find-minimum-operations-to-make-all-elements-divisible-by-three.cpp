class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(auto n:nums){
            int a= n%3;
            ans+=min(abs(a-0),abs(a-3));
        }
        return ans;
    }
};

/*
1   2   3   4

1   2   0   1

1   1   0   1


*/