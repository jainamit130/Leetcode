class Solution {
public:
    long long countSubstrings(string s) {
        vector<int> nineModMap(9);
        vector<int> sevenModMap(7);
        long long ans = 0;
        for(int i=0;i<s.length();i++) {
            int digit = s[i]-'0';
            // No matter what num it is need to update the 9 and 7 mod map
            updateModMap(digit,nineModMap,9);
            updateModMap(digit,sevenModMap,7);
            if(digit == 1 || digit == 2 || digit == 5) ans+=i+1;
            if(digit == 3 || digit == 6) ans+=nineModMap[0]+nineModMap[3]+nineModMap[6];
            if(digit == 4) {
                if(i-1>=0 && ((s[i-1]-'0')*10 + 4)%4 == 0) ans+=i+1;
                else ans += 1;
            }
            if(digit == 8) {
                ans += 1;
                if(i-1>=0 && ((s[i-1]-'0')*10 + 8)%8 == 0) ans += 1;
                if(i-2>=0 && ((s[i-2]-'0')*100 + (s[i-1]-'0')*10 + 8)%8 == 0) ans += i-1;
            } 
            if(digit == 7) ans += sevenModMap[0];
            if(digit == 9) ans += nineModMap[0];
        }
        return ans;
    }

    void updateModMap(int digit, vector<int>& modMap, int divisor) {
        vector<int> newUpdatedMod(divisor);
        newUpdatedMod[digit%divisor]=1;
        for(int rem=0;rem<divisor;rem++) {
            if(modMap[rem]!=0) newUpdatedMod[(rem*10+digit)%divisor] += modMap[rem];
        }
        int i = 0;
        // if(divisor == 9){
        // for(auto n:newUpdatedMod) {
        //     cout<<"newUpdatedMod["<<i<<"] -> "<<n<<endl;
        //     i++;
        // }}
        // cout<<endl;
        modMap = newUpdatedMod;
        return;
    }
};


/*

1   2   9   3   6


0*



*/