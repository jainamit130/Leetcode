class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return solve(to_string(finish),0,limit,1,s)-solve(to_string(start-1),0,limit,1,s);
    }

    long long solve(string& upperLimit,int index,int& limit,int isTight,string& s) {
        if(upperLimit.length()<s.length()) return 0;
        if(upperLimit.length()==s.length()) return min(upperLimit,s)==s?1:0;
        if(index==upperLimit.length()-s.length()) return isTight?min(upperLimit.substr(index),s)==s?1:0:1;
        int upperDigit = isTight?min(upperLimit[index]-'0',limit):limit;
        long long ans = 0;
        ans += (upperDigit)*1LL*solve(upperLimit,index+1,limit,false,s);
        ans += solve(upperLimit,index+1,limit,isTight&&upperDigit==upperLimit[index]-'0',s);
        return ans; 
    }
};


/*
5
3

a   b   c   d   e
        i

limit 7

536     540

        424
0-4 0-7 0-7 => 5*8*8
5  0-2  0-7 => 3*8
    3   0-6 => 7  


9   7   1
    7   2

0-9



1   1   1   0   9   6   0   9   5   9   9   8   5


*/