class Solution {
    public char kthCharacter(long k, int[] operations) {
        for(char ch='a';ch<'z';ch++) {
            if(isValid(ch,operations,k)) return ch;
        }
        return 'z';
    }

    boolean isValid(char ch,int[] operations,long position) {
        int index = (int)Math.ceil(Math.log(position)/Math.log(2))-1;
        long power = (long) Math.pow(2, Math.ceil(Math.log(position) / Math.log(2)));
        if(index==-1) return ch=='a';
        if(operations[index]==1) {
            return isValid((char)((ch-'a'-1+26)%26+'a'),operations,position-(power/2));
        }
        return isValid(ch,operations,position-(power/2));
    }
}

/*


aa => aabb => aabbaabb => aabbaabbbbccbbcc 


x >= log2(k)

1 => dec char by 1
0 => do nothing

*/