class Solution {
public:
    int trap(vector<int>& height) {
        stack<vector<int>> st;
        int n=height.size();
        vector<vector<int>> nextMaxHeight(n,{-1,-1});
        for(int i=height.size()-1;i>=0;i--){
            if(height[i]==0){
                continue;
            } else {
                vector<int> nextGreater={-1,-1};
                while(!st.empty() && st.top()[0]<height[i]){   
                    if(st.top()[0]>nextGreater[0]){
                        nextGreater=st.top();
                    }
                    st.pop();
                }
                if(!st.empty() && st.top()[0]>nextGreater[0]){
                    nextGreater=st.top();
                }
                nextMaxHeight[i]=nextGreater;
                st.push({height[i],i});
            }
        }
        bool noSnowMode=false;
        int endActivation=-1;
        int ans=0;
        for(int i=0;i<nextMaxHeight.size();){
            if(nextMaxHeight[i][0]==-1){
                if(i==endActivation){
                    noSnowMode=false;
                    endActivation=-1;
                }
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
                ans+=abs(nextMaxHeight[i][1]-i-1)*min(height[i],nextMaxHeight[i][0]);
                noSnowMode=true;
                endActivation=nextMaxHeight[i][1];
                i++;
            }
        }
        return ans;
    }
};