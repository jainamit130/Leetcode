class Solution {
public:
    int ans=0;
    int l,r;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        l=lower,r=upper;
        vector<long long> prefix;
        prefix.push_back(0);
        int n=nums.size();
        // O(n)
        for(int i=0;i<n;i++){
            prefix.push_back(prefix.back()+nums[i]);
        }
        mergeSort(prefix,0,n);
        return ans;
    }

    vector<long long> mergeSort(vector<long long>& prefix,int start,int end){
        if(start==end){
            return {prefix[start]};
        }

        vector<long long> a,b;
        if(start<end){
            int mid = start+(end-start)/2; 
            a = mergeSort(prefix,start,mid);
            b = mergeSort(prefix,mid+1,end);
        }
        for(int i=0;i<a.size();i++){
            ans+=getNumsInRange(b,a[i]+l,a[i]+r);
        }
        return merge(a,b);
    }

    vector<long long> merge(vector<long long>& a,vector<long long>& b){
        vector<long long> c;
        int i=0,j=0;

        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j]){
                c.push_back(a[i]);
                i++;
            } else {
                c.push_back(b[j]);
                j++;
            }
        }

        while(i<a.size()){
            c.push_back(a[i]);
            i++;
        }

        while(j<b.size()){
            c.push_back(b[j]);
            j++;
        }

        return c;
    }

    int getNumsInRange(vector<long long>& nums,long long lower,long long upper){
        int index1=lower_bound(nums.begin(),nums.end(),lower)-nums.begin();
        int index2=upper_bound(nums.begin(),nums.end(),upper)-nums.begin();
        return index2-index1;
    }
};



/*

-3  4   -8  2   4   -1

0   -3  1   -7  -5  -1  -2

-2 - (x) >= -3 => -2 + 3 >= x =>  1>=x
-2 - (x) <=  3 => -2 - 3 <= x => -5<=x

-5 <= x <= 1

-10 - -4 => 0
-9 - -3
-8 - -2 => 2
-7 - -1
-3->   -6 - 0 => 1
-5 - 1 => 5
-4 - 2 => 3
-3 - 3
-2 - 4 => 1

-3 to +3


*/