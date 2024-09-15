class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<vector<int>>> left(n,vector<vector<int>>(k+1,vector<int>(129,0)));
        vector<vector<vector<int>>> right(n,vector<vector<int>>(k+1,vector<int>(129,0)));

        left[0][1][nums[0]]=1;
        for(int i=1;i<n;i++){
            left[i][1][nums[i]]=1;
            for(int subSize = 1; subSize<=k; subSize++){
                for(int vals = 0;vals<=128;vals++){
                    if(left[i-1][subSize][vals]){
                        left[i][subSize][vals]=1;
                    }
                    if(left[i-1][subSize-1][vals]){
                        left[i][subSize][vals|nums[i]]=1;
                    }
                }
            }
        }

        right[n-1][1][nums[n-1]]=1;
        for(int i=n-2;i>=0;i--){
            right[i][1][nums[i]]=1;
            for(int subSize = 1;subSize<=k ; subSize++){
                for(int vals=0;vals<=128;vals++){
                    if(right[i+1][subSize][vals]){
                        right[i][subSize][vals]=1;
                    }
                    if(right[i+1][subSize-1][vals]){
                        right[i][subSize][vals|nums[i]]=1;
                    }
                }
            }
        }

        int result=0;
        for(int i=1;i<n;i++){
            for (int g = 0; g < 128; ++g) {
                if(left[i-1][k][g]){
                    for (int v = 0; v < 128; ++v) {
                        if(right[i][k][v])
                            result=max(result,g^v);
                    }
                }
            }
        }

        return result;
    }
};

/*


log2 (2^7) = 7

k = 2

    4      2      5         6           7
0   0      0      0         0           0       
1   4      4,2    4,2,5     4,2,5,6    4,2,5,6,7
2          2,6    2,6,5,7   2,6,5,7     2,6,5,7


4      2      5      6        7

5,6,7   6,7     7       7

            






*/