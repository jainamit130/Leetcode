class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int start{ 0 }, end{ static_cast<int>(arr.size() - 1) };
        while (start < end && arr[start] <= arr[start + 1]) ++start;
        if (start == end) return 0;
        while (end >= 1 && arr[end] >= arr[end - 1]) --end;

        int minLen{ static_cast<int>(end) };
        for (int i{ 0 }; i <= start; ++i) {
            auto lb = std::lower_bound(arr.begin() + end, arr.end(), arr[i]);
            int c{ static_cast<int>(lb - arr.begin()) };
            minLen = std::min(minLen, c - i - 1);
        }

        return minLen;
    }
};

// class Solution {
// public:
//     int findLengthOfShortestSubarray(vector<int>& arr) {
//         int i=1,j=arr.size()-2;
//         int ans = arr.size();
//         for(;i<arr.size();i++){
//             if(arr[i]<arr[i-1]){
//                 break;
//             } 
//         }

//         for(;j>=0;j--){
//             if(arr[j]>arr[j+1]){
//                 break;
//             } 
//         }
//         cout<<i<<" "<<j<<endl;
//         int index1 = upper_bound(arr.begin(),arr.begin()+i-1,arr[j+1])-arr.begin();
//         int index2 = lower_bound(arr.begin()+j+1,arr.end(),arr[i-1])-arr.begin();
//         cout<<index1<<" "<<index2<<endl;
//         if(i==arr.size() || j<0){
//             return 0;
//         }
//         ans = min(j-index1+1,index2-i+1);
//         if(i>j){
//             ans = min(ans,i-j+1);
//         }
//         return ans;
//     }
// };