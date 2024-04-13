class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            int g=i;
            while(!st.empty() && st.top().first>heights[i]){
                g=st.top().second;
                maxArea=max(maxArea,(i-g)*st.top().first);
                st.pop();
            }
            st.push({heights[i],g});
        }
        int ti=heights.size()-1;
        while(!st.empty()){
            int h=st.top().first;
            int hi=st.top().second;
            maxArea=max(maxArea,(ti-hi+1)*h);
            st.pop();
        }
        return maxArea;
    }
};



/*
5   4   1   2
    i    
maxArea=
Stack: 5,0

*/


/*


2   1   5   6   2   3
                    i

maxArea= 10
5,3     
Stack: 0,1     



*/