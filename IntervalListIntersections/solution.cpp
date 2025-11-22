class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ret;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            int l = max(firstList[i][0], secondList[j][0]);
            int u = min(firstList[i][1], secondList[j][1]);
            if (l <= u) ret.push_back({l, u});
            if (firstList[i][1] < secondList[j][1]) ++i;
            else ++j;
        }
        return ret;
    }
};

// Basically, we have 2 pointers going through both lists
// If an intersection exists, it'll be between max(interval1_begin, interval2_begin) and min(interval1_end, interval2_end)
// We increment through the lists based on the interval that ended first
