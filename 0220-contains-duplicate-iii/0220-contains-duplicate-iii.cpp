#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;

class Solution {
public:
    using o_set = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int i=0,j=0;
        o_set st;
        while(i<nums.size()){
            if(j<nums.size() && j-i+1<=indexDiff+1){
                if(st.find(nums[j])!=st.end()){
                    return true;
                }
                st.insert(nums[j]);
                j++;
            } else if(j<nums.size()) {
                st.erase(st.find(nums[i]));
                i++;
            }

            if(j-i==indexDiff+1 || j==nums.size()){
                if(valueDiff==0){
                    if(j==nums.size()){
                        i++;
                    }
                    continue;
                }
                int searchMaxVal=nums[i]+valueDiff;
                int searchMinVal=nums[i]-valueDiff;

                auto maxValInd=st.order_of_key(searchMaxVal);
                auto valInd=st.order_of_key(nums[i]);
                auto minValInd=st.order_of_key(searchMinVal);
                
                auto maxVal=*st.find_by_order(maxValInd);
                auto val=*st.find_by_order(valInd);
                auto minVal=*st.find_by_order(minValInd);

                if(maxVal==searchMaxVal || searchMinVal==minVal){
                    return true;
                }

                if(maxValInd-valInd+1>2 || (valInd-minValInd+1>1 && minVal>searchMinVal)){
                    return true;
                }
                if(j==nums.size()){
                    i++;
                }
            }
        }
        return false;
    }
};


/*

iD= 2
vD= 3

1   5   9   1   5   9


9   
5 









*/