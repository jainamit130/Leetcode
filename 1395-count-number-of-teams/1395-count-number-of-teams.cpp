class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        for(int i=1;i<rating.size()-1;i++){
            int smaller1=0;
            int larger1=0;
            int smaller2=0;
            int larger2=0;
            for(int j=0;j<rating.size();j++){
                if(i==j){
                    continue;
                }
                if(j<i){
                    if(rating[j]<rating[i])
                        smaller1++;
                    if(rating[j]>rating[i])
                        larger2++;
                } else {
                    if(rating[j]>rating[i])
                        larger1++;
                    if(rating[j]<rating[i])
                        smaller2++;
                }
            }
            ans+=smaller1*larger1;
            ans+=smaller2*larger2;

        }
        return ans;
    }
};



// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         int maxElement = *max_element(rating.begin(), rating.end());
//         vector<vector<vector<int>>> cache(rating.size()+1, vector<vector<int>>(4, vector<int>(maxElement + 2, -1)));
//         int asc=solve(rating,0,0,0,0,cache);
//         cache= vector<vector<vector<int>>> (rating.size()+1, vector<vector<int>>(4, vector<int>(maxElement + 2, -1)));
//         int desc=solve(rating,0,0,maxElement+1,1,cache);
//         return asc+desc;
//     }

//     int solve(vector<int>& ratings,int index,int currSize,int lastElement,bool isDesc,vector<vector<vector<int>>>& cache){
//         if(currSize==3){
//             return 1;
//         }
//         if((2-currSize+index)>=ratings.size()){
//             return 0;
//         }

//         if(cache[index][currSize][lastElement]!=-1){
//             return cache[index][currSize][lastElement];
//         }

//         int ans=0;
//         if(!isDesc){
//             ans+=solve(ratings,index+1,currSize,lastElement,isDesc,cache);
//             if(lastElement<ratings[index]){
//                 ans+=solve(ratings,index+1,currSize+1,ratings[index],isDesc,cache);
//             }
//         } else {
//             ans+=solve(ratings,index+1,currSize,lastElement,isDesc,cache);
//             if(lastElement>ratings[index]){
//                 ans+=solve(ratings,index+1,currSize+1,ratings[index],isDesc,cache);
//             }
//         }
//         return cache[index][currSize][lastElement]=ans;
//     }
// };


/*

2   5   3   4   1


     5
__   __   __




*/