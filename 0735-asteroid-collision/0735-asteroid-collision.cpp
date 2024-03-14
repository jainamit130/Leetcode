class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        st.push(asteroids[asteroids.size()-1]);
        for(int i=asteroids.size()-2;i>=0;i--){
            int flag=0;
            while(!st.empty()){
                if(st.top()<0 && asteroids[i]>0){
                    if(abs(st.top())==abs(asteroids[i])){
                        st.pop();
                        flag=1;
                        break;
                    } else if(abs(st.top())>abs(asteroids[i])){
                        flag=1;
                        break;
                    } else {
                        st.pop();
                    }
                } else {
                    break;
                }
            }
            if(!flag)
                st.push(asteroids[i]);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};