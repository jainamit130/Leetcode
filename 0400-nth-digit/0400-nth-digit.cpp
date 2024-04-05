class Solution {
public:
    int findNthDigit(int n) 
    {
        long long digit = 9;
        int first = 1;
        int length = 1;
        while(n>digit*length)
        {
            n = n - digit*length;
            length++;
            first = first * 10;
            digit = digit * 10;
        }
        first = first + (n - 1)/length;
        string str = to_string(first);
        return str[(n - 1)%length] - '0';
    }
};