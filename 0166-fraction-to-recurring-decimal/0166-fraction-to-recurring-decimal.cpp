class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans="";
        string dec="";
        long q = (long)numerator/(long)denominator;
        if(numerator<0 && denominator>0 || numerator>0 && denominator<0)
            ans+="-";
        ans+=to_string(abs(q));
        long r = (long)numerator % (long)denominator;
        if(r==0)
            return ans;
        else {
            ans+=".";
            map<long,int> mp;
            int i=0;
            while(r!=0){
                if(mp.find(r)!=mp.end()){
                    dec.insert(mp[r],"(");
                    dec+=")";
                    break;
                } else  
                    mp[r]=i;
                i++;
                r=(long)r*10;
                q=r/denominator;
                r=r%denominator;
                dec+=to_string(abs(q));
            }            
        }
        return ans+dec;
    }
};