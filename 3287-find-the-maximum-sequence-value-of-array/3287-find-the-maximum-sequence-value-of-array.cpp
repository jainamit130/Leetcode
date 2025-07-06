class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n= nums.size();
        vector<vector<vector<int>>> left(n,vector<vector<int>>(k+1,vector<int>(129,0)));
        vector<vector<vector<int>>> right(n,vector<vector<int>>(k+1,vector<int>(129,0)));
        
        left[0][1][nums[0]]=1;
        for(int i=1;i<n;i++){
            left[i][1][nums[i]]=1;
            for(int subsize = 1;subsize <=k; subsize++){
                for(int vals=0; vals<=128; vals++){
                    if(left[i-1][subsize][vals]){
                        left[i][subsize][vals]=1;
                    }

                    if(left[i-1][subsize-1][vals]){
                        left[i][subsize][vals|nums[i]]=1;
                    }
                }
            }
        }

        right[n-1][1][nums[n-1]]=1;
        for(int i=n-2;i>=0;i--){
            right[i][1][nums[i]]=1;
            for(int subsize = 1;subsize <=k; subsize++){
                for(int vals=0; vals<=128; vals++){
                    if(right[i+1][subsize][vals]){
                        right[i][subsize][vals]=1;
                    }

                    if(right[i+1][subsize-1][vals]){
                        right[i][subsize][vals|nums[i]]=1;
                    }
                }
            }
        }

        int result=0;
        for(int i=0;i<n-1;i++){
            for(int vals1=0;vals1<=128;vals1++){
                if(left[i][k][vals1]){
                    for(int vals2=0;vals2<=128;vals2++){
                        if(right[i+1][k][vals2]){
                            result=max(result,vals1^vals2);
                        }
                    }
                }
            }
        }
        return result;
    }
};





/*







*/