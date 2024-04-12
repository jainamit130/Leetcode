class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int maxGap=2;
        int gap=1;
        for(int i=0;i<hBars.size()-1;i++){
            if(hBars[i]+1==hBars[i+1]){
                gap++;
            } else {
                gap=1;
            }
            maxGap=max(gap+1,maxGap);
        }
        int maxGap1=2;
        gap=1;
        for(int i=0;i<vBars.size()-1;i++){
            if(vBars[i]+1==vBars[i+1]){
                gap++;
            } else {
                gap=1;
            }
            maxGap1=max(gap+1,maxGap1);
        }
        return pow(min(maxGap,maxGap1),2);
    }
};