/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        return guessTheNumber(1,n);
    }

    int guessTheNumber(int low,int high){
        int mid=((long)high+(long)low)/2;
        if(guess(mid)==0)
            return mid;
        else if(guess(mid)==-1)
            return guessTheNumber(low,mid-1);
        else if(guess(mid)==1)
            return guessTheNumber(mid+1,high);
        return mid;
    }
};