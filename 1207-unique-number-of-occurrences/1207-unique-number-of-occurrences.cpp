class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> mp(2001);
        unordered_set<int> s;
        for(auto n:arr){
            mp[n+1000]++;
        }
        for(auto count:mp){
            if(count!=0 && s.find(count)!=s.end())
                return false;
            s.insert(count);
        }
        return true;
    }
};

// class Solution {
// public:
//     bool uniqueOccurrences(vector<int>& arr) {
//         vector<int> occur;
//         sort(arr.begin(),arr.end());
//         int c=1;
//         for(int i=1;i<arr.size();i++){
//             if(arr[i]==arr[i-1])
//                 c++;
//             else {
//                 if(find(occur.begin(),occur.end(),c)==occur.end())
//                 {
//                     occur.push_back(c);
//                     c=1;
//                 }
//                 else
//                     return false;
//             }
//         }
//         if(find(occur.begin(),occur.end(),c)!=occur.end())
//             return false;
//         return true;       
//     }
// };