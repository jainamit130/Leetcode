class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(),maximumHeight.end(),greater<int>());
        long long ans=0;
        int currH=INT_MAX;
        for(auto n:maximumHeight){
            if(currH<=n){
                currH-=1;
            } else {
                currH=n;
            }
            if(currH==0){
                return -1;
            }
            ans+=(long long)currH;
        }
        return ans;
    }
};



/*

4   2   

currHeight = 4

4   3   3   2

4
3
2
1




*/