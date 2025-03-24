class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int freeDays = 0;
        int lastMeetingEnd = 0;

        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            if (start > lastMeetingEnd + 1) {
                freeDays += (start - lastMeetingEnd - 1);
            }

            lastMeetingEnd = max(lastMeetingEnd, end);
        }

        if (lastMeetingEnd < days) {
            freeDays += (days - lastMeetingEnd);
        }

        return freeDays;
    }
};