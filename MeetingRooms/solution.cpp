/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        Interval prev = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            Interval interval = intervals[i];
            if (interval.start < prev.end) return false;
            else prev = interval;
        }

        return true;
    }
};

// Overlapping intervals algorithm with instant boolean return false if overlapping intervals
