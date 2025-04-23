class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        long long runningSum = 0;
        int currMaxVal = 0;
        int freq = 0;
        long long operations = 0;
        int ans = 0;
        int oldMax = 0;
        while(j<nums.size()) {
            runningSum += freq;
            oldMax = currMaxVal;
            currMaxVal = nums[j];
            freq = 0;
            while(j<nums.size() && currMaxVal==nums[j]) {
                freq++; j++;
            }

            operations += runningSum*(currMaxVal - oldMax);

            while(i<j && operations>k) {
                operations -= currMaxVal - nums[i]; 
                runningSum -= 1;
                i++;
            }
            if(operations<=k) ans = max(ans,j-i);
        }
        return ans;
    }
};


/*


Given: nums => vector<int> => positive >=1; can have duplicates
       k    => int         =>  positive >= 1

Return: int => max possible freq of an elment after performing at most k operations

Constraints

len(nums) => 1e5
k         => 1e5

Ex:

nums: 1   3   3   2   1   4   
k = 3

1 -> 2
2 -> 1,0; 2,1; 3,2 
3 -> 2,0; 3,1; 4,3; 5,5
4 -> 1,0; 2,1; 3,2; 4,4; 



1   1   2   3   3   4

a..   b..   c..  d.. e.. f   

a -> g
b -> h
c -> i
d -> j
e -> k
f -> l

contribution => x
new contribution => x + 

g*4 + h*3 + i*2 + j*1 + k*0 => prev value

g*5 + h*4 + i*3 + j*2 + k*1 + l*0 => g*4 + h*3 + i*2 + j*1 + k*0 + g+h+i+j+k 
                                  => prev value + running sum of all values
.....  v->y


Approach:
1. sort the array
2. initiate a sliding window
3. increase j to include a all occurences of a new distinct element and the contribution added would be the prefix sum in window but before increasing j also add the last max value * number of occurences to the prefix sum
4. loosing a element is as simple as loosing a max val - lost val contribution
5. maintain the max window such that the val of contribution is below k
6. window size (already maximised) is our ans

1 2 4
i
    j

maxVal = 2
freq = 1
runningSum = 3
operations = 1
ans = 2


1   1   1   2   2   4   4


3*1  +  2*0  => 

3*3  +  2*2 => 3*1 + 2*0 + (3+2)*2


1   2   4

1*1 + 1*0

1*3 + 1*2 => 1*1 + 1*0 + (1+1)*2

*/