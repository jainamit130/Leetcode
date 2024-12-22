class Solution {
public:
    int minLength(string s, int numOps) {
        int start = 1;
        int end = s.length();
        int ans = end;
        while(start<=end) {
            int mid = (start+end)/2;
            if(isPossible(numOps,s,mid)) {
                ans = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return ans;
    }

    bool check(string& s, int numOps, int mid, char startChar){
    for(int i = 0; i < s.size(); ++i){
        if(startChar == s[i]) numOps--;
        startChar = (startChar == '0')?'1':'0';
    }
    return (numOps >= 0);
}

    bool isPossible(int numOps,string s,int maxPossibleLen) {
        if(maxPossibleLen==1) return check(s, numOps, maxPossibleLen, '1') || check(s, numOps, maxPossibleLen, '0');
        int len = 1;
        for(int i=1;i<=s.length();i++) {
            if(i<s.length() && s[i]==s[i-1]) {
                len++;
            } else {
                if(len>maxPossibleLen) {
                    int opReq = (len/(maxPossibleLen+1));
                    if(opReq>numOps) {
                        return false;
                    } else {
                        numOps -= opReq;
                    }
                }
                len=1;
            }
        }
        return true;
    }
};



/*

len/2^x = maxPossibleLen

log2(len/maxPossibleLen) = x

1   1   1   1   1   1


*/