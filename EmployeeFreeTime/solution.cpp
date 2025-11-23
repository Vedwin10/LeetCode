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
    /**
     * @param schedule: a list schedule of employees
     * @return: Return a list of finite intervals 
     */
    vector<Interval> employeeFreeTime(vector<vector<int>> &schedule) {
        vector<pair<int, int>> vect;
        for (const auto& employee : schedule) {
            for (int i = 0; i < employee.size()-1; i+=2) {
                vect.push_back({employee[i], 1});
                vect.push_back({employee[i+1], -1});
            }
        }

        sort(vect.begin(), vect.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        int count = 0;
        int prev = -1;
        vector<Interval> res;
        for (const auto& [time, val] : vect) {
            if (count == 0 && prev != -1 && prev != time) res.push_back(Interval(prev, time));
            count += val;
            if (count == 0) prev = time;
        }

        sort(res.begin(), res.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });

        return res;
    }
};

// Run the Meeting Rooms II algorithm, except instead of counting the max number of intervals at one point, count when there are 0 intervals ongoing, and store those intervals
// Note that this solution assumes the schedule vector is inputted like this: [[1,2,3,4],[1,2]] instead of [[[1,2],[3,4]],[1,2]], adjust solution accordingly
