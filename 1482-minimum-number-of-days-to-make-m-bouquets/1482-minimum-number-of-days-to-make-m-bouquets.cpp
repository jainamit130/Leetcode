class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<((long long)m*k))
            return -1;
        int maxDay=0;
        for(auto b:bloomDay){
            maxDay=max(maxDay,b);
        }
        int i=1,j=maxDay;
        int ans=INT_MAX;
        while(i<=j){
            int mid=(i+j)/2;
            int t=bloomed(mid,bloomDay,m,k);
            if(t){
                j=mid-1;
            } else {
                i=mid+1;
            }
        }
        return i;
    }

    bool bloomed(int day,vector<int>& bloomDay,int m,int k){
        int adj = k;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                adj--;
            } else {
                adj=k;
            }
            if(adj==0){
                m--;
                adj=k;
            }
        }
        return (m<=0);
    }
};


/*

7   7   7   7   12  7   7

7   7   12  12  12  

1   10  3   10  2

1   10  3   10  2   4

10  10  10  10  4



*/