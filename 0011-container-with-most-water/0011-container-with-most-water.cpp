class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans=(j-i)*min(height[i],height[j]);
        while(i<j){
            if(height[j]<height[i])
                j--;
            else
                i++;
            ans=max(ans,(j-i)*min(height[i],height[j]));
        }
        return ans;
    }
};