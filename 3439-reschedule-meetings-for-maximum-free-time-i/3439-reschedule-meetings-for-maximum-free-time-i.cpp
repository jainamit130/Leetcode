class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int i=0,j=0;
        int n = startTime.size();
        int meetingDuration = 0;
        // just get the window size as k
        while(j<k) {
            meetingDuration+=endTime[j]-startTime[j];
            j++;
        }

        int freeDuration = 0;
        if(j==n) {
            freeDuration = eventTime - meetingDuration;
        } else {
            freeDuration = startTime[j]-meetingDuration;
        }

        while(j<n) {
            meetingDuration-=endTime[i]-startTime[i];
            meetingDuration+=endTime[j]-startTime[j];
            j++;
            if(j==n) {
                freeDuration = max(freeDuration,eventTime - endTime[i] - meetingDuration);
            } else {
                freeDuration = max(freeDuration,startTime[j] - endTime[i] - meetingDuration);
            }
            i++;
        }

        return freeDuration;
    }
};