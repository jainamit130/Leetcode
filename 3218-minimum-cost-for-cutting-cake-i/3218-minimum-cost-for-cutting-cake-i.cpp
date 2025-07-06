class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int hFactor=1;
        int vFactor=1;
        int i=m-2;
        int j=n-2;
        int ans=0;
        sort(horizontalCut.begin(),horizontalCut.end());
        sort(verticalCut.begin(),verticalCut.end());
        while(i>=0 && j>=0){
            if(horizontalCut[i]<verticalCut[j]){
                ans+=verticalCut[j]*hFactor;
                vFactor+=1;
                j--;
            } else {
                ans+=horizontalCut[i]*vFactor;
                hFactor+=1;
                i--;
            }
        }

        while(i>=0){
            ans+=horizontalCut[i]*vFactor;
            i--;
        }

        while(j>=0){
            ans+=verticalCut[j]*hFactor;
            j--;
        }
        return ans;
    }
};