// class Solution {
// public:
//     int trap(vector<int>& height) {
//         if(height.size()==1)
//             return 0;
//         int temp=INT_MIN;
//         vector<pair<int,int>> leftrightheights(height.size(),{INT_MIN,INT_MIN});
//         for(int i=0;i<height.size();i++){
//             temp=max(height[i],temp);
//             leftrightheights[i].first=temp;
//         }
//         temp=INT_MIN;
//         for(int i=height.size()-1;i>=0;i--){
//             temp=max(height[i],temp);
//             leftrightheights[i].second=temp;
//         }
//         int ans=0;
//         for(int i=0;i<height.size();i++){
//             int collectWater=min(leftrightheights[i].first,leftrightheights[i].second)-height[i];
//             collectWater=(collectWater<=0)?0:collectWater;
//             ans+=collectWater;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==1)
            return 0;
        int maxL=height[0],maxR=height.back();
        int i=0,j=height.size()-1;
        int ans=0;
        while(i<=j){
            if(maxL<=maxR){
                int t=maxL-height[i];
                ans+=(t<=0)?0:t;
                maxL=max(maxL,height[i]);
                i++;
            } else {
                int t=maxR-height[j];
                ans+=(t<=0)?0:t;
                maxR=max(maxR,height[j]);
                j--;
            }
        }
        return ans;
    }
};

