class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int i=0;
        while(num){
            int bit = num&1;
            if(bit==0){
                ans|=(1<<i);
            } 
            i++;
            num=num>>1;
        }
        return ans;
    }
};