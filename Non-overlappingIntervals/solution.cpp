class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

        vector<int> prev = intervals[0];
        int ret = 0;

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> interval = intervals[i];
            if (interval[0] < prev[1]) {
                ++ret;
            } else {
                prev = interval;
            }
        }

        return ret;
    }
};

// Merge Interval algorithm
// Instead of sorting by a[0] < b[0], we sort by a[1] < b[1]. We do this because we want to minimize the number of overlapping intervals we remove, so if our interval endings 
// are always as small as possible, the condition to check for an overlapping interval (interval[0] < prev[1]) won't be true as often as if we had a really big interval in the beginning, 
// so this optimizes local decisions to give us a greedy algorithm.
// The condition interval[0] < prev[1] is not inclusive (<=) based on the examples given in the problem. [1,2] and [2,3] are considered OK.
// Instead of merges, simply increment the return variable.