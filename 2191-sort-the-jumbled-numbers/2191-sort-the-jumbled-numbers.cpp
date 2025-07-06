class Solution {
public:
static bool cmp(pair<int,int>&a,pair<int,int>&b){
    return (a.second<b.second);
}
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>dummy;
        for(int i=0;i<nums.size();i++){
            int number=nums[i];
            int neww=0;
            stack<int>s;
            if(number==0){
                s.push(number);
            }
            while(number!=0){
                int index=number%10;
                s.push(index);
                number/=10;
            }
            while(!s.empty()){
                int index=s.top();
                s.pop();
                neww=neww*10+mapping[index];
            }
            dummy.push_back({nums[i],neww});
        }
        int n=dummy.size();
        // for(int i=0;i<n-1;i++){
        //    for(int j=0;j<n-1;j++){ 
        //       if(dummy[j]>dummy[j+1]){
        //         swap(dummy[j],dummy[j+1]);
        //         swap(nums[j],nums[j+1]);
        //       }
        //    }
        // }
       
        sort(dummy.begin(),dummy.end(),cmp);
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(dummy[i].first);
        }
        return ans;
        
    }
};