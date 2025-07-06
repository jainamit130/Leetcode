class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b){return a[1] < b[1];});
        priority_queue<int> heap;
        int now = 0;
        for (int i = 0; i < courses.size(); ++ i)
        {
            heap.push(courses[i][0]);
            now += courses[i][0];
            if (now > courses[i][1])
                now -= heap.top(), heap.pop();
        }
        return heap.size();
    }
};


/*
0|----------|100    100|----------------------|1100   1100|------|1300
                

2 6 8 => 6
5 6 11 => 12
6 10 16 => 22
9 3 12 => 25 
10 3 13 => 28
10 6 16 => 34


2 6 8 
5 6 11 => 6
6 10 16 => 16
9 3 12 => 19 
10 3 13 => 22
10 6 16 => 28


2 6 8 
5 6 11 
6 10 16 => 10
9 3 12 => 13
10 3 13 => 16
10 6 16 => 22


2 6 8 
5 6 11 
6 10 16 
9 3 12 => 3
10 3 13 => 6
10 6 16 => 12




*/