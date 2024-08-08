class Solution {
public:
    int trap(vector<int>& height) {
        stack<vector<int>> st;
        int n=height.size();
        vector<vector<int>> nextHeight(n,{-1,-1});
        for(int i=n-1;i>=0;i--){
            vector<int> nextGreater={-1,-1};
            while(!st.empty() && st.top()[0]<height[i]){
                if(nextGreater[0]<st.top()[0]){
                    nextGreater=st.top();
                }
                st.pop();
            }
            if(!st.empty()){
                nextGreater=st.top();
            }
            nextHeight[i]=nextGreater;
            st.push({height[i],i});
        }

        bool noSnowMode=false;
        int endActivation=-1;
        int ans=0;
        for(int i=0;i<n;){
            if(nextHeight[i][0]==-1){
                i++;
                continue;
            }
            if(noSnowMode){
                if(i==endActivation){
                    noSnowMode=false;
                    endActivation=-1;
                } else {
                    ans-=height[i];
                    i++;
                }
            } else {
                ans+=abs(nextHeight[i][1]-i-1)*min(height[i],nextHeight[i][0]);
                noSnowMode=true;
                endActivation=nextHeight[i][1];
                i++;
            }
        }
        return ans;
    }
};