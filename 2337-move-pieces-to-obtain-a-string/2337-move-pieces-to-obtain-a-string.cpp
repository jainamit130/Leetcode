class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,j=0;
        while(i<start.length()||target.length()) {
            while(i<start.length() && start[i]=='_') {
                i++;
            }
            while(j<target.length() && target[j]=='_') {
                j++;
            }
            if(i<start.length() && j<target.length()) {
                if(start[i]!=target[j] || (i<j && start[i]=='L') || (i>j && start[i]=='R')) return false;
                else {i++;j++;}
            } else {
                return i==start.length() && j==target.length();
            }
        }
        return true;
    }
};



/*

clarifying questions:

1. start and target only contains L,R and _ ? yes
2. length of start and target is equal ? yes
3. start and target can have in the boundary places a _? yes
4. target and start are empty then? return true

Question:

_   L   R   _ => START

L   _   _   R => TARGET


_   _   L   R   => start
L   R   _   _    =>target


start can have a _ while a target can have a R/L => 
if it is a L then the first non dash thing to the right of _ should be a L
if it is a R then the first non dash thing to the left of _ should be a R

The only thing that is critical is a L and R cannot cross each other
in target in can keep track of groups of L and R 
and the same exact number and groups ordering should be present in start ignoring all the dashes

Approach:

iterate start and target together in such a way as ignore the dashes and increment that pointer which lacks the extra character in the other if mismatched count then return false; 


*/