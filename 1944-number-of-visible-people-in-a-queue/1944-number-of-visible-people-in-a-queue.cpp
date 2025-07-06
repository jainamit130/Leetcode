class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> ans(heights.size());
        stack<int> st;
        for(int i=heights.size()-1;i>=0;i--){
            int visible=0;
            while(!st.empty() && st.top()<heights[i]){
                visible++;
                st.pop(); 
            }
            if(!st.empty())
                visible++;
            ans[i]=visible;
            st.push(heights[i]);
        }
        return ans;
    }
};


/*

10  6   8   5   11  9
                    i

v=0

result: 0    

st: 11   



*/