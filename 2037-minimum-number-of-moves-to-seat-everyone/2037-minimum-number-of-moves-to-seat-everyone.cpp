class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int ans=0;
        for(int i=0;i<seats.size();i++){
            ans+=abs(seats[i]-students[i]);
        }
        return ans;
    }
};



/*

1   3   5
2   7   4
1   2   1


1   4   5   9
1   2   3   6
0   2   2   3





2   2   6   6   
1   2   3   6

1   0   3   0
*/