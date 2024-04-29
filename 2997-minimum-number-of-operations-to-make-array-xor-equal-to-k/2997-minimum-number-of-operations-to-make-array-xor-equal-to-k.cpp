class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<20;i++){
            int currBitOfK = (k>>i) & 1;
            int zeroCount= 0;
            int oneCount= 0;
            for(int j=0;j<nums.size();j++){
                int currBitOfCurrNums = (nums[j]>>i) & 1; 
                if(currBitOfCurrNums)
                    oneCount++;
                else
                    zeroCount++;
            }
            oneCount=oneCount%2;
            zeroCount=zeroCount%2;
            int r=0;
            if(oneCount && zeroCount && oneCount==zeroCount)
                r=1;
            else
                r=oneCount>zeroCount?1:0;
            // cout<<currBitOfK<<" "<<oneCount<<" "<<zeroCount<<" "<<r<<endl;
            if(currBitOfK!=r)
                ans++;
        }
        return ans;
    }
};

/*
1   1   1   1   1 => 1
0   0   0   0   0 => 0
1   1   1   0   0 => 1
0   0   0   1   1 => 0
1   1   0   0     => 0


*/