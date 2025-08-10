class Solution {
private:
    int shipDays(vector<int>& weights, int shipCapacity) {
        int days = 1;
        int capacity = 0;
        for (auto weight : weights) {
            if (capacity + weight > shipCapacity) {
                days++;
                capacity = weight;
            } else {
                capacity += weight;
            }
        }
        return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(begin(weights), end(weights), 0);
        while (l < r) {
            int m = (l + r) / 2;
            if (shipDays(weights, m) <= days) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};