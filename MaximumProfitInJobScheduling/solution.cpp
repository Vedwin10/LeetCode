class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // build a vector of intervals for sorting
        int n = (int)startTime.size();
        vector<vector<int>> intervals(n);
        for (int i = 0; i < n; ++i) {
            intervals[i] = {startTime[i], endTime[i], profit[i]};
        }

        // sort by interval beginning
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // memoization (1-indexed) the size of the maximum time
        vector<int> MaxProfit(n+1);

        // initialize base case
        MaxProfit[0] = 0;

        // traverse in order of dependency
        for (int i = 1; i <= n; ++i) {
            vector<int> interval = intervals[i-1];
            MaxProfit[i] = max(MaxProfit[i-1], BinarySearch(i-1, intervals, MaxProfit) + interval[2]);
        }

        return MaxProfit[n];
    }

    // binary search finds the highest interval x where x[1] <= start, and returns MaxProfit[x]
    int BinarySearch(int i, vector<vector<int>>& intervals, vector<int>& MaxProfit) {
        int l = 0, r = i-1;
        int best = -1;
        int start = intervals[i][0];
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (intervals[m][1] <= start) {
                best = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return MaxProfit[best+1];
    }
};

// This is my explanation of the dynamic programming approach broken down very precisely:

/*

Let MaxProfit(i) denote the recursive function of the subproblems that define this dynamic programming problem. 
MaxProfit(i) gives the maximum possible profit that can be obtained from taking jobs 1 to i, inclusive. 
Note that MaxProfit[n] gives us the solution, where n = the number of jobs given. 
At each subproblem/job, we can choose to either include the job, or not include the job. 
If we don't choose the job, then MaxProfit[i] = MaxProfit[i-1], aka it's just the same as the max profit up to the previous job. 
But if we do choose to include the job, then we need to choose the maximum between MaxProfit[i-1] and MaxProfit[x] + profit(i), 
where x is the first job that has an end <= start of job i, and profit(i) is the profit that the job i gives. 
We can memoize this problem into a dynamic problem with a 1D array going from i=1 to i=n, 
and then return MaxProfit[n] as the solution. The base case is MaxProfit[0] = 0.

We must also sort the intervals vector in terms of endTime, because we need to guarantee that for a current job i, we're evaluating
it under the assumption that all jobs that ended before it have been processed. We need to do this in the case of small intervals
inside large intervals. We need to process the small intervals first, because we need to know the MaxProfit if those were considered.
Processing the large intervals first would make the small intervals not even considered. The formula would be 
max(large interval, prev interval + profit(small interval)). This is wrong. The large interval hasn't ended, so technically
considering the profit from the large interval is NOT correct. 

In order to find the latest ending interval x where end[x] <= start[i] for a job i, we use binary search searching for the rightmost
value <= start[i].

Putting all of this together, our algorithm runs in O(n * logn).

*/