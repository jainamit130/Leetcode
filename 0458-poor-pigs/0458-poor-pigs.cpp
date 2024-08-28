class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int trials = minutesToTest/minutesToDie;
        int pigs=0;
        while(pow(trials+1,pigs)<buckets){
            pigs++;
        }
        return pigs;
    }
};