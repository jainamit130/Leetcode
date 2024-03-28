#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
#define pbds tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        pbds arr1;
        pbds arr2;
        arr1.insert(nums[0]);
        arr2.insert(nums[1]);
        vector<int> realArr1={nums[0]};
        vector<int> realArr2={nums[1]};
        int index=2;
        while(index<nums.size()){
            int g1=arr1.size()-arr1.order_of_key(nums[index]+1);
            int g2=arr2.size()-arr2.order_of_key(nums[index]+1);
            // cout<<"Real Arr1: ";
            // for(auto n:realArr1)
            //     cout<<n<<" ";
            // cout<<endl;
            // cout<<"Real Arr2: ";
            // for(auto n:realArr2)
            //     cout<<n<<" ";
            // cout<<endl;
            // cout<<nums[index]<<" g1 = "<<g1<<" ,g2 = "<<g2<<" arr1 size = "<<arr1.size()<<" arr2 size = "<<arr2.size()<<endl;
            if(g1>g2){
                arr1.insert(nums[index]);
                realArr1.push_back(nums[index]);
            } else if(g2>g1) {
                arr2.insert(nums[index]);
                realArr2.push_back(nums[index]);
            } else if(realArr1.size()<=realArr2.size()){
                arr1.insert(nums[index]);
                realArr1.push_back(nums[index]);
            } else if(realArr1.size()>realArr2.size()){
                arr2.insert(nums[index]);
                realArr2.push_back(nums[index]);
            } 
            // cout<<"Real Arr1: ";
            // for(auto n:realArr1)
            //     cout<<n<<" ";
            // cout<<endl;
            // cout<<"Real Arr2: ";
            // for(auto n:realArr2)
            //     cout<<n<<" ";
            // cout<<endl;
            // cout<<endl;
            index++;
        }
        for(auto n:realArr2){
            realArr1.push_back(n);
        }
        return realArr1;
    }
};



/*

2   47  3   3   65  7   97  4
                i

arr1 =  2   
arr2 =  47  3  

*/