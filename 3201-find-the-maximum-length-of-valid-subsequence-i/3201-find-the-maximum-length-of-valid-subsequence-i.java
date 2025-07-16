class Solution {
    public int maximumLength(int[] nums) {
        int totalO = 0;
        int totalE = 0;
        int altStartE = 0;
        int isLastOdd = 1;
        int altStartO = 0;
        int isLastEven = 1;
    
        for(int i=0;i<nums.length;i++) {
            if(nums[i]%2==0) {
                totalE++;
                if(isLastOdd==1) {
                    altStartE++;
                    isLastOdd = 0;
                } 
                if(isLastEven==0) {
                    altStartO++;
                    isLastEven = 1;
                } 
            } else {
                totalO++;
                if(isLastOdd==0) {
                    altStartE++;
                    isLastOdd = 1;
                } 
                if(isLastEven==1) {
                    altStartO++;
                    isLastEven = 0;
                } 
            }
        }
        return Math.max(totalO,Math.max(totalE,Math.max(altStartO,altStartE)));
    }
}