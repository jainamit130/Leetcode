class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;
        for(int i=0;i<s.length();i++) {
            long long cost1=0;
            int str1 = s[i]-'a';
            while(str1!=(t[i]-'a')){
                cost1+=previousCost[str1];
                str1--;
                if(str1<0){
                    str1=25;
                }
            }

            long long cost2=0;
            int str2 = s[i]-'a';
            while(str2!=(t[i]-'a')){
                cost2+=nextCost[str2];
                str2++;
                str2=str2%26;
            }
            long long cost = min(cost1,cost2); 
            ans+=cost;
        }
        return ans;
    }
};