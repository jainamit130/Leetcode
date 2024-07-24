class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& vec) {
        vector<vector<int>> nums;
        for(int i=0;i<vec.size();i++){
            nums.push_back({getMapVal(mapping,vec[i]),i});
        }
        sort(nums.begin(),nums.end(),[&](auto lhs,auto rhs){
            if(lhs[0]==rhs[0])
                return lhs[1]<rhs[1];
            return lhs[0]<rhs[0];
        });
        vector<int> ans(vec.size());
        for(int i=0;i<vec.size();i++){
            ans[i]=vec[nums[i][1]];
        }
        return ans;
    }

    int getMapVal(vector<int>& mapping,int x){
        if (x==0) return mapping[0];
        int z=0;
        for(int pow10=1; x>0; pow10*=10){
            auto [q, r]=div(x, 10);
            z+=mapping[r]*pow10;
            x=q;
        }
        return z;
    }
};