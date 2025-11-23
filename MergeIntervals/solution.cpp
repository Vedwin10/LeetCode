class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        vector<vector<int>> merged;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= prev[1]) {
                prev[1] = max(prev[1], intervals[i][1]);
            } else {
                merged.push_back(prev);
                prev = intervals[i];
            }
        }
        merged.push_back(prev);

        return merged;
    }
};

// Sort the intervals array to ensure that intervals[i][0] is always < intervals[i+1][1], so that you can simply check if
// the next intervals beginning overlaps with the previous intervals' end
// use the prev variable to keep track of the previous interval, can't just use i-1 because intervals get merged and gaps can be >= 2
// if the current interval you're comparing has no overlap, you can add prev to the solution. Then lastly add the final interval
// before returning the solution
