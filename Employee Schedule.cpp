/*


Link: https://leetcode.com/problems/employee-free-time

Problem: Employee Free Time
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.

Example 2:

Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]


*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Definition for an Interval.
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct comparator
{
    bool operator()(const Interval &lhs, const Interval &rhs)
    {
        return lhs.end > rhs.end;
    }
};

class Solution
{
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> &schedule)
    {
        vector<Interval> res;
        vector<Interval> res1;
        vector<Interval> res2;
        priority_queue<Interval, vector<Interval>, comparator> pq;
        for (int i = 0; i < schedule.size(); i++)
        {
            for (int j = 0; j < schedule[i].size(); j++)
            {
                pq.push(schedule[i][j]);
            }
        }
        while (!pq.empty())
        {
            res1.push_back(pq.top());
            pq.pop();
        }
        int i = 0;
        while (i < res1.size())
        {
            int s = res1[i].start;
            int e = res1[i].end;
            i++;
            while (i < res1.size() && res1[i].start <= e)
            {
                s = min(res1[i].start, s);
                e = res1[i].end;
                i++;
            }
            Interval n(s, e);
            res2.push_back(n);
        }
        for (int i = 0; i < res2.size() - 1; i++)
        {
            if (res2[i].end < res2[i + 1].start)
            {
                Interval t(res2[i].end, res2[i + 1].start);
                res.push_back(t);
            }
        }
        return res;
    }
};

// Function to print intervals in a vector
void printIntervals(const vector<Interval> &intervals)
{
    cout << "[";
    for (int i = 0; i < intervals.size(); ++i)
    {
        if (i > 0)
            cout << ", ";
        cout << "[" << intervals[i].start << ", " << intervals[i].end << "]";
    }
    cout << "]" << endl;
}

int main()
{
    Solution sol;

    // Test Case 1
    vector<vector<Interval>> schedule1 = {{{1, 2}, {5, 6}}, {{1, 3}}, {{4, 10}}};
    cout << "Test Case 1:\n";
    auto result1 = sol.employeeFreeTime(schedule1);
    printIntervals(result1); // Expected output: [[3, 4]]

    // Test Case 2
    vector<vector<Interval>> schedule2 = {{{1, 3}, {6, 7}}, {{2, 4}}, {{2, 5}, {9, 12}}};
    cout << "\nTest Case 2:\n";
    auto result2 = sol.employeeFreeTime(schedule2);
    printIntervals(result2); // Expected output: [[5, 6], [7, 9]]

    // Test Case 3 (Single employee with no gaps)
    vector<vector<Interval>> schedule3 = {{{1, 2}, {3, 4}, {5, 6}}};
    cout << "\nTest Case 3:\n";
    auto result3 = sol.employeeFreeTime(schedule3);
    printIntervals(result3); // Expected output: [[2, 3], [4, 5]]

    // Test Case 4 (Overlapping intervals across employees)
    vector<vector<Interval>> schedule4 = {{{1, 5}}, {{2, 3}}, {{4, 6}}};
    cout << "\nTest Case 4:\n";
    auto result4 = sol.employeeFreeTime(schedule4);
    printIntervals(result4); // Expected output: []

    // Test Case 5 (No overlapping intervals)
    vector<vector<Interval>> schedule5 = {{{1, 2}}, {{3, 4}}, {{5, 6}}};
    cout << "\nTest Case 5:\n";
    auto result5 = sol.employeeFreeTime(schedule5);
    printIntervals(result5); // Expected output: [[2, 3], [4, 5]]

    // Test Case 6 (Mixed intervals with overlaps and gaps)
    vector<vector<Interval>> schedule6 = {{{1, 3}, {5, 7}}, {{2, 4}}, {{6, 8}}};
    cout << "\nTest Case 6:\n";
    auto result6 = sol.employeeFreeTime(schedule6);
    printIntervals(result6); // Expected output: [[4, 5]]

    return 0;
}