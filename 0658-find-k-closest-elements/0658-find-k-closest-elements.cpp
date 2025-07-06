class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int i=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(i==n || (i>0 && abs(arr[i]-x)>=abs(arr[i-1]-x))){
            i--;
        }
        k--;
        int j=i;
        while(k){
            if(i==0 && j<n-1){
                j++;
            } else if(j==n-1 && i>0){
                i--;
            } else {
                if(x-arr[i-1]<=arr[j+1]-x){
                    i--;
                } else {
                    j++;
                }
            }
            k--;
        }

        vector<int> ans;
        for(int k=i;k<=j;k++){
            ans.push_back(arr[k]);
        }
        return ans;
    }
};


/*


1   2   3   4   5   6   7   8   9   
        i
                    j

*/