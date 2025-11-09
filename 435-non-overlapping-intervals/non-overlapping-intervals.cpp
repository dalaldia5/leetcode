class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end());

        int cnt = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                cnt++;
                prevEnd = min(prevEnd, intervals[i][1]);
            } else {
                prevEnd = intervals[i][1];
            }
        }

        return cnt;
    }
};
