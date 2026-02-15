class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        string ans = "";
        while(i>=0 || j>=0) {
            int bitA = 0, bitB = 0;
            if(i>=0) bitA = a[i]-'0';
            if(j>=0) bitB = b[j]-'0';
            int sumBit = (bitA + bitB + carry)%2;
            ans+=(sumBit+'0');
            carry = bitA && bitB || bitA && carry || bitB && carry;
            i--; j--;
        }
        ans+=(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


/*

0   0   0   -   0   0
0   0   1   -   1   0
0   1   0   -   1   0
0   1   1   -   0   1
1   0   0   -   1   0
1   0   1   -   0   1   
1   1   0   -   0   1
1   1   1   -   1   1



*/