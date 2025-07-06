class Solution {
public:
    int radix = 26;
    int mod = 1e9+7;
    int maxWeight = -1;
    int getMaxWeight(int maxLength) {
        int maxWeight = 1;
        for(int i=1;i<=maxLength;i++) {
            maxWeight = (1LL*maxWeight*radix)%mod;
        }
        return maxWeight;
    }

    int getInitialHashFunc(string s,int len) {
        int sLen = s.length();
        int radixFactor = 1;  
        int hash = 0;
        for(int i=len-1;i>=0;i--) {
            int index = i%sLen;
            hash = (hash + ((s[index]-'a'+1)*1LL*radixFactor) % mod) % mod;
            radixFactor=(radixFactor*1LL*radix)%mod;
        }
        return hash;
    } 

    bool check(int index,string a,string b) {
        for(int i=0;i<b.length();i++) {
            int aIndex = (index+i)%a.length();
            if(a[aIndex]!=b[i]) return false;
        }
        return true;
    }

    int repeatedStringMatch(string a, string b) {
        int bLen = b.length();
        int aLen = a.length();
        int maxWeight = getMaxWeight(bLen); 
        int hashB = getInitialHashFunc(b,bLen);
        int hashA = getInitialHashFunc(a,bLen);
        int ans = ceil(bLen/(double)aLen);
        int index = bLen%aLen;
        while((ans)<=bLen) {
            int startIndex = ((index - bLen) % aLen + aLen) % aLen;
            if(hashA==hashB && check(startIndex,a,b)) {
                return ans;
            }
            hashA = ((hashA * 1LL * radix) % mod - ((a[startIndex] - 'a' + 1) * 1LL * maxWeight) % mod + (a[index] - 'a' + 1) + mod) % mod;            
            if(index==0) ans++;
            index = (index+1)%aLen;
        }
        return -1;
    }
};


/*


Clarifying questions

1. given 2 string => a and b? yes
2. both string will contain lowercase english alphabets? yes
3. if a is empty and b is not then? not possible both string have min 1 length
4. if not possible return -1? yes

Example:

a   b   c   d

a   b   c   d   a   b   c   d   a   b   c   d   
        c   d   a   b   c   d   a   b

Conclusions

1. Starting part of string b is a end substring of a
2. Ending part of string b is a start substring of a
3. in the middle i have few complete strings of a 
4. if i keep repeating a until it becomes equal to or bigger than b and than b only then i can check for b 

Brute Force will be:
keep repeating a to form a string equal to b and then check if b can be formed 
if not then add a one more time and then recheck if b can be formed 

O(2*n^2) time complexity


c   d   a   b   c   d   a   b   c   d   a   b


*/