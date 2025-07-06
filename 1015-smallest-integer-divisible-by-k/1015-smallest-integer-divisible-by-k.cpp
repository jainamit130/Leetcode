class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> seen;
        int num=1%k;
        int len=1;
        while(true){
            int mod=num;
            if(seen.find(mod)!=seen.end())
                return -1;
            if(mod==0)
                return len;
            seen.insert(mod);
            num=(num*10+1)%k;
            len++;
        }
        return -1;
    }
};