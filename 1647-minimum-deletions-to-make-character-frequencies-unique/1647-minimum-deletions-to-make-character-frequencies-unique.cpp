class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> charFreq;
        // O(n)
        for(auto ch:s) {
            charFreq[ch]++;
        }

        priority_queue<int> maxHeap;
        maxHeap.push(0);
        // O(26)
        for(auto [ch,count]:charFreq) {
            maxHeap.push(count);
        }
        int ans = 0;
        int lastFreq = maxHeap.top();
        maxHeap.pop();
        int lastCount = 0;
        while(!maxHeap.empty()) {
            int freq = maxHeap.top();
            maxHeap.pop();
            if(freq==0) {
                ans += lastCount;
                if(lastFreq-freq>1) {
                    lastCount=max(0,lastCount-(lastFreq-freq-1));
                    ans += lastCount;
                }
                break;
            }
            if(lastFreq==freq) {
                lastCount++; 
            } else {
                ans += lastCount;
                lastCount=max(0,lastCount-(lastFreq-freq-1));
                lastFreq = freq;
            }
        }
        return ans;
    }
};


/*

2   2   2

ans = 4 + 6 + 7

String is Good - if not 2 different charcaters in s have the same frequency
Clarifications =>

String s would contain all alphabets? lowercase? yes
string s cannot be empty => yes

Ex:

a   a   a   a   b   b   b   c   c   d   d   e   e   f

ans = 1 + 1 + 2 + 2 = 6 

4 -> 1
3 -> 1
2 -> 1
1 -> 3

a single frequency can have mutiple characters as high as 26
freq -> a   b   c   d   e   ....

size-1 

16 - 11 = 5 operations

Step 1 => get the freq alphabet to count freq O(n)
Step 2 => turn the above freq into a sorted map with key as freq and the value as the number of times that freq was encountered (freq of freq) O(26log (26))
Step 3 => iterate the map and keep transferring the remaning to the next key until exhausted and at this point the carried over is coagulated into our answer O(26)

a   c   c   d   c   d   a   d   d   d   b   a   a   d   b   c

a - 4
b - 2
c - 4
d - 6


*/