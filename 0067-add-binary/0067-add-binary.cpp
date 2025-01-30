class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        string ans = "";
        while(i>=0 && j>=0) {
            int aNum = a[i]-'0';
            int bNum = b[j]-'0';
            int rNum = aNum^bNum^carry;
            ans += (char)(rNum+'0');
            int count1 = 0;
            if(aNum==1) {
                count1++;
            }
            if(bNum==1) {
                count1++;
            }
            if(carry==1) {
                count1++;
            }
            if(count1>=2) carry = 1;
            else carry = 0;
            i--;
            j--;
        }

        while(i>=0) {
            int aNum = a[i]-'0';
            int rNum = aNum^carry;
            ans += (char)(rNum+'0');
            int count1 = 0;
            if(aNum==1) {
                count1++;
            }
            if(carry==1) {
                count1++;
            }
            if(count1>=2) carry = 1;
            else carry = 0;
            i--;
        }

        while(j>=0) {
            int bNum = b[j]-'0';
            int rNum = bNum^carry;
            ans += (char)(rNum+'0');
            int count1 = 0;
            if(bNum==1) {
                count1++;
            }
            if(carry==1) {
                count1++;
            }
            if(count1>=2) carry = 1;
            else carry = 0;
            j--;
        }
        if(carry==1) {
            ans += (char)(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


/*

How long is the string

can the string be all 0's

can there be preceeding 0's

no other character other than 0 or 1

1 + 1 = 0 and carry 1 
1 + 0 = 1 
0 + 0 = 0


1^1^1 = 1 carry 1 
1^1^0 = 0 carry 1
1^0^1 = 0 carry 1
1^0^0 = 0 carry 0
0^1^1 = 0 carry 1
0^1^0 = 1 carry 0
0^0^1 = 1 carry 0
0^0^0 = 0 carry 0
*/