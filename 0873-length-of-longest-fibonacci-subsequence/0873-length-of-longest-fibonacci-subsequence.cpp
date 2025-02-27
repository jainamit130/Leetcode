class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        unordered_set<int> st(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-2;i++) {
            for(int j=i+1;j<arr.size()-1;j++) {
                int num1 = arr[i];
                int num2 = arr[j];
                int subAns = 2;
                // generate as long as we can
                while(st.find(num1+num2)!=st.end()) {
                    cout<<num1+num2<<endl;
                    int temp = num2;
                    num2 = num1+num2;
                    num1 = temp;
                    subAns++;
                    ans = max(ans,subAns);
                }
            }
        }
        return ans;
    }
};