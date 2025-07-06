class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>ans ;
        int n = nums.size() ;

        for(int i=0 ; i<n ; i++){
            nums[i] = nums[i]%2;
        }

        vector<int>v;

        for(int i=1 ; i<n ; i++){
            if(nums[i] == nums[i-1]){
                v.push_back(i);
            }
        }

        int m = v.size();

        for(auto q : queries){
            int st = q[0];
            int end = q[1];

            int l = 0 ;
            int r = m - 1 ;
            int mid ;

            int a = -1 ;
            int b = -1 ;

            while(l<=r){
                mid = l + (r-l)/2;
                if(v[mid] > st){
                    a = v[mid] ;
                    r = mid - 1 ;
                }
                else{
                    l = mid + 1 ;
                }
            }

            l = 0 ;
            r = m - 1 ;

            while(l<=r){
                mid = l + (r-l)/2;
                if(v[mid] <= end){
                    b = v[mid] ;
                    l = mid + 1 ;
                }
                else{
                    r = mid - 1 ;
                }
            }

            if( a != -1 && b != -1 && st< b && end >= a ){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }

        }

        return ans ;
        
    }
};