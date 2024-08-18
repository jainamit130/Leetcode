class Solution {
public:
    string largestPalindrome(int n, int k) {
        switch (k) {
            case 1:
                return string(n, '9'); // k==1 => 9 max palindrome
            case 2:
                if (n<=2) {     // max palindrome of 2 digit => 88 if 1 digit then 8
                    return string(n, '8');
                } else {   // max palindrome of 3 digit then in between i can have 9's => ex: 89998
                    return "8"+string(n-2, '9')+"8";
                }
            case 3:   // all 9's would be divisible by 3 so => ex: 999999
                return string(n, '9');
            case 4:
                if (n<=4) { // n<=4 then all 8's
                    return string(n, '8');
                } else { // but n>4 then we can have last 2 digits as 8 so that it is divisible by 4 so we need to fix 1st 2 digits as well to 8 middles can be 9 
                    return "88" + string(n-4, '9') + "88";
                }
            case 5:
                if (n<=2) { // n<=2 => 55 or 5
                    return string(n, '5');
                } else { // n>2 => first and last would be 5 middles would be 9
                    return "5" + string(n-2, '9') + "5";
                }
            case 6:
                if (n<=2) { // n==1 then 6 or n==2 then 66
                    return string(n, '6');
                } else if (n==3) {  // n==3 then 888
                    return "888";
                } else { 
                    if (n%2==0) {  // n==4 or 6 or 8.... then at the end i need 798 for it to be divisible by 6
                        return "8" + string((n-4)/2, '9') + "77" + string((n-4)/2, '9') + "8";
                    } else { // n==5 or 7 or 9.... then at the end i can have a even greater that is 89898
                        return "8" + string((n-3)/2, '9') + "8" + string((n-3)/2, '9') + "8";
                    }
                }
            case 7: {
                unordered_map<int, string> mp = {
                    {0, ""},
                    {1, "7"},
                    {2, "77"},
                    {3, "959"},
                    {4, "9779"},
                    {5, "99799"},
                    {6, "999999"},
                    {7, "9994999"},
                    {8, "99944999"},
                    {9, "999969999"},
                    {10, "9999449999"},
                    {11, "99999499999"}
                };
                int l = n/12, r = n%12;
                string b = "";
                for (int i=0;i<l;i++) b+="999999";
                return b + mp[r] + b;
            }
            case 8:
                if (n<=6) {
                    return string(n, '8');
                } else {
                    return "888" + string(n-6, '9') + "888";
                }
            case 9:
                return string(n, '9');
            default:
                return string(n, '9');
        }
    }
};