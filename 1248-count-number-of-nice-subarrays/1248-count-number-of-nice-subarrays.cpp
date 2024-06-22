class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ansCnt = 0; 
        int cnt = 0;   
        int i = 0, j = 0; 

        while (j < nums.size()) {
            if (nums[j] % 2 != 0) { 
                k--; 
                cnt = 0; 
            }
            
            while (k == 0) { 
                if (nums[i] % 2 != 0) { 
                    k++;
                }
                cnt++; 
                i++; 
            }
            
            ansCnt += cnt; 
            j++; 
        }

        return ansCnt; 
    }
};


/*

2   2   2   1   2   2   1   2   1   2



*/