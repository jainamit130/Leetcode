class Solution {
public:
    long long vectorToNum(vector<int>& nums){
        long long num=0;
        for(int i=0;i<nums.size();i++){
            num=num*10+nums[i];
        }
        return num;
    }
    
    long long factorial(int n){
        long long prod=1;
        for(int i=2;i<=n;i++){
            prod*=i;
        }
        return prod;
    }

    long long permutations(map<int,int> mp,int n){
        long long totalCount=factorial(n); // n!
        for(auto [num,commonIntegerCount]: mp){
            totalCount/=factorial(commonIntegerCount); // n!/(commonIntegerCount!)
        }
        return totalCount;
    }

    set<map<int,int>> mp_st;
    long long countGoodIntegers(int n, int k) {
        vector<int> num(n); 
        genratingPermutations(num,0,n-1,k);

        long long ans=0;
        for(auto mp:mp_st){
            ans+= permutations(mp,n);
            if(mp.find(0)!=mp.end() && mp[0]>0){
                mp[0]--;
                ans-=permutations(mp,n-1);
            } 
        }
        return ans;
    }

    // 10^(n/2)  
    void genratingPermutations(vector<int>& nums,int left,int right,int k){
        if(left>right){
            long long palindromicNum = vectorToNum(nums);
            if(palindromicNum%k==0){
                map<int,int> mp1;
                while(palindromicNum){
                    mp1[palindromicNum%10]++;
                    palindromicNum/=10;
                }
                mp_st.insert(mp1);
            }
            return; 
        }
        for(int digit=0; digit<=9; digit++){
            if(digit==0 && left==0){
                continue;
            } 
            nums[left]=digit;
            nums[right]=digit;
            genratingPermutations(nums,left+1,right-1,k);
        }
    }
};


/*

n=3 k=5


5   5   2   3 => n! / (commonIntegers!) - permutationsStartingWithZero


5   5   0   2 => 0   5  5   2  => 3!/2!
5 -> 2
0 -> 0
2 -> 1

5   0   5 => 550;  505 => 2 (Edge Case)
5   1   5 => 551;  515; 155 => 3
5   2   5 => 3
5   3   5 => 3
5   4   5 => 3
5   5   5 => 1 (Edge Case)
5   6   5 => 3
5   7   5 => 3
5   8   5 => 3
5   9   5 => 3
 Total = 27 possibilities


Steps :

1=> Generate All Palindromic Numbers  which are divisible by k and of total length n => 
Ex: n=5 

0   0   0   0   0
1   0   0   0   1
1   1   0   1   1
1   1   1   1   1
1   2   0   2   1


4   6   7   6   4


6   4   7   4   6




10^(n/2)


*/