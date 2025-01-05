class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            for(int k=1; k<=nums.size()-i; k++) { 
                vector<int> arr;
                for(int j=i;j<k+i;j++) {
                    arr.push_back(nums[j]);
                }
                if(prod(arr)==gcd(arr)*1LL*lcm(arr)) {
                    ans = max(ans,k);
                }
            }
        }
        return ans;
    }

    long long prod(vector<int> arr) {
        long long prod = 1;
        for(auto n:arr) {
            prod=prod*n;
            if(prod>2520) {
                return prod;
            }
        }
        return prod;
    }

    long long lcm(vector<int> arr) {
        vector<int> nums(11);
        for(int i=0;i<arr.size();i++) {
            for(int j=2;j<=arr[i];j++) {
                int count = 0;
                while(arr[i]%j==0) {
                    count++;
                    arr[i]/=j;
                }
                nums[j] = max(count,nums[j]);
            }   
        }
        long long lcm = 1;
        for(int i=2;i<nums.size();i++){
            if(nums[i]>0) {
                lcm*=pow(i,nums[i]);
            }
        }
        return lcm;
    }

    long long gcd(vector<int> arr) {
        vector<int> nums(11);
        for(int i=0;i<arr.size();i++) {
            for(int j=2;j<=arr[i];j++) {
                if(arr[i]%j==0){
                    nums[j]++;
                }
            }
        }
        
        long long gcd = 1;
        for(int i=2;i<nums.size();i++){
            if(nums[i]==arr.size())
                gcd=i; 
        }
        return gcd;
    }
};


/*

2   3   4   5   6

2   6   24
2   1   1
2   6   12

*/