class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
         vector<int> bit1freq(32);
         int i=0,j=0;
         int result=INT_MAX;
         int AND = nums[j];
         while(j<nums.size()){
            AND=AND&nums[j];
            result=min(abs(k-AND),result);
            updateBitFreq(bit1freq,nums[j],1);  
            if(AND==k){
                return 0;
            } else if(AND<k){
                while(AND<k && i<=j){
                    updateBitFreq(bit1freq,nums[i],-1);
                    AND=0;
                    i++;
                    int size=j-i+1;
                    for(int t=0;t<32;t++){
                        if(size==bit1freq[t]){
                            AND=AND|(1<<t);
                        } 
                    }
                    result=min(abs(k-AND),result);
                }
            }
            j++;
         }
         return result;
    }

    void updateBitFreq(vector<int>& bit1Freq,int num,int incdec){
        int i=0;
        while(num>0){
            if(num&1){
                bit1Freq[i]+=incdec;
            }
            num=num>>1;
            i++;
        }
    }
};

/*



*/