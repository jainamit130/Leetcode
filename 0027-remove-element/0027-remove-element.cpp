class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int t=0;
       for(int s=0;s<nums.size();s++){
           if(nums[s]==val){
               continue;
            //    cout<<s<<endl;
           }
            else if(s<nums.size()){
                // cout<<s;
                nums[t]=nums[s];
                t++;
            }
            // cout<<s<<endl;
       }
       return t;
    }
};