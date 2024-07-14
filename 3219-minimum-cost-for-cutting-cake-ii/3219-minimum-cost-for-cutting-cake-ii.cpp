class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(),horizontalCut.end());
        sort(verticalCut.begin(),verticalCut.end());
        int i=m-2;
        int hFactor=1;
        int vFactor=1;
        long long ans=0;
        int j=n-2;
        while(i>=0 && j>=0){
            if(horizontalCut[i]>verticalCut[j]){
                vFactor+=1;
                ans+=(long long)horizontalCut[i]*hFactor;
                i--;  
            } else if(horizontalCut[i]<verticalCut[j]) {
                hFactor+=1;
                ans+=(long long)verticalCut[j]*vFactor; 
                j--;
            } else {
                if(m-hFactor>n-vFactor){
                    hFactor+=1;
                    ans+=verticalCut[j]*vFactor; 
                    j--;
                } else {
                    vFactor+=1;
                    ans+=(long long)horizontalCut[i]*hFactor;
                    i--; 
                }
            }
        }

        while(i>=0){
            ans+=(long long)horizontalCut[i]*hFactor;
            i--;  
        }

        while(j>=0){
            ans+=(long long)verticalCut[j]*vFactor; 
            j--; 
        }
        return ans;
    }
};