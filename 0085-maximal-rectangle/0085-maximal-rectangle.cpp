class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        vector<vector<int>> matrix(mat.size(),vector<int>(mat[0].size()));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                matrix[i][j]=mat[i][j]-'0';
            }
        }

        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]!=0)
                    matrix[i][j]=matrix[i][j]+matrix[i-1][j];
            }
        }

        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            ans=max(ans,largestRectangleArea(matrix[i]));
        }        
        return ans;
    }

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
            maxArea=max(maxArea,(ti-st.top().second+1)*st.top().first);
            st.pop();
        }
        return maxArea;
    }
};



/*

1   0   1   0   0               1   0   1   0   0 => 1
1   0   1   1   1               2   0   2   1   1 => 3
1   1   1   1   1               3   1   3   2   2 => 3
1   0   0   1   0               4   0   0   3   0 => 1




*/