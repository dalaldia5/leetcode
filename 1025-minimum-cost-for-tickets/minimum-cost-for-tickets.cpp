class Solution {
public:
    int f(vector<int>& days, unordered_set<int> st, vector<int>& costs, int idx,
          vector<int>& dp) {
        int n = dp.size();
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        if (st.find(idx) == st.end()) {
            return dp[idx] = f(days, st, costs, idx + 1, dp);
        }
        int cost1 = costs[0] + f(days, st, costs, idx + 1, dp);
        int cost2 = costs[1] + f(days, st, costs, idx + 7, dp);
        int cost3 = costs[2] + f(days, st, costs, idx + 30, dp);
        return dp[idx] = min(cost1, min(cost2, cost3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int maxDays = days[n - 1];
        unordered_set<int> st;
        for (auto it : days) {
            st.insert(it);
        }
        vector<int> dp(maxDays + 1, -1);
        return f(days, st, costs, 0, dp);
    }
};