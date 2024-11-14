class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(),quantities.end());
        int m = quantities.size();
        int start = 1;
        int end = quantities.back();
        int ans=end;
        while(start<=end) {
            int mid = (start+end)/2;
            int index = lower_bound(quantities.begin(),quantities.end(),mid)-quantities.begin();
            int totalShopsReq = 0;
            for(int i=index;i<m;i++) {
                totalShopsReq+=ceil(quantities[i]/(double)mid);
            }
            totalShopsReq+=index;
            cout<<index<<" "<<mid<<" "<<totalShopsReq<<endl;
            if(totalShopsReq<=n){
                ans = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return ans;
    }
};

/*


2   6   10



*/