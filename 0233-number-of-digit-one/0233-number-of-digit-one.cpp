class Solution {
public:
    int countDigitOne(int n) {
        return solve(n,0,0);
    }

    int solve(int n,int bitNo,int next){
        if(n==0){
            return 0;
        }

        int ans=0;
        int currBit=n%10;
        if(currBit!=0){
            //Own Contribution
            if(currBit==1){
                ans+=next+1;
            } else {
                if(bitNo==0){
                    ans+=1;
                } else {
                    ans+=pow(10,bitNo);
                }
            }
            //Other contributions
            int i=bitNo-1;
            while(i>=0){
                ans+=currBit*pow(10,bitNo-1);
                i--;
            }
        }
        ans+=solve(n/10,bitNo+1,currBit*pow(10,bitNo)+next);
        return ans;
    }
};