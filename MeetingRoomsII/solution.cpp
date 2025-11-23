class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> meetings;
        for (const auto& interval : intervals) {
            meetings.push_back({interval.start, 1});
            meetings.push_back({interval.end, -1});
        }

        sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        int count = 0, max = 0;
        for (const auto& meeting : meetings) {
            count += meeting.second;
            if (count > max) max = count;
        }

        return max;
    }
};

// Essentially we want to know the maximum number of meetings going on at any given point in time
// We can start this by having a running count of how many meetings are currently going on, add +1 every time a new meeting starts, and -1 every time an old one ends
// Using an array of meetings start/end times and 1/-1 respectively, we can traverse the (sorted) array adding the second value and updating the max value
// Array should be sorted by first value, and tiebreakers are dealt with by ending old meetings first, and then starting new ones
