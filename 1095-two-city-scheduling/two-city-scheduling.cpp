class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        //{abs diff, index}
        vector<pair<int,int>> diff;
        for (int i = 0; i < n; i++) {
            int d = abs(costs[i][0] - costs[i][1]);
            diff.push_back({d, i});
        }
        // sort descending (max diff first)
        sort(diff.begin(), diff.end(), greater<pair<int,int>>());
        int countA = 0, countB = 0;
        int limit = n / 2;
        int sum = 0;
        for (auto &p : diff) {
            int i = p.second;
            int costA = costs[i][0];
            int costB = costs[i][1];
            // If A is cheaper
            if (costA < costB) {
                if (countA < limit) {
                    sum += costA;
                    countA++;
                } else {
                    sum += costB;
                    countB++;
                }
            }
            // If B is cheaper
            else {
                if (countB < limit) {
                    sum += costB;
                    countB++;
                } else {
                    sum += costA;
                    countA++;
                }
            }
        }
        return sum;
    }
};