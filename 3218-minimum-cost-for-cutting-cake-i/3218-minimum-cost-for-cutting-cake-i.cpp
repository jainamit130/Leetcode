class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(),horizontalCut.end());
        sort(verticalCut.begin(),verticalCut.end());
        int i=m-2;
        int hFactor=1;
        int vFactor=1;
        int ans=0;
        int j=n-2;
        while(i>=0 && j>=0){
            if(horizontalCut[i]>verticalCut[j]){
                vFactor+=1;
                ans+=horizontalCut[i]*hFactor;
                i--;  
            } else if(horizontalCut[i]<=verticalCut[j]) {
                hFactor+=1;
                ans+=verticalCut[j]*vFactor; 
                j--;
            } 
        }

        while(i>=0){
            ans+=horizontalCut[i]*hFactor;
            i--;  
        }

        while(j>=0){
            ans+=verticalCut[j]*vFactor; 
            j--; 
        }
        return ans;
    }
};