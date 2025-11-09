class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        // insert the new interval in the correct position
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            i++;
        }
        intervals.insert(intervals.begin() + i, newInterval);

        // merge overlapping intervals
        for (int j = 0; j < intervals.size() - 1; j++) {
            if (intervals[j][1] >= intervals[j + 1][0]) {
                intervals[j][0] = min(intervals[j][0], intervals[j + 1][0]);
                intervals[j][1] = max(intervals[j][1], intervals[j + 1][1]);
                intervals.erase(intervals.begin() + j + 1);
                j--;
            }
        }
        return intervals;
    }
};
