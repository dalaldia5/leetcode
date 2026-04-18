class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return 0;
        if (k > n / 2) return -1;
        vector<long long> cost(n);
        for (int i = 0; i < n; i++) {
            long long l = nums[(i - 1 + n) % n];
            long long r = nums[(i + 1) % n];
            long long maxi = max(l, r);
            cost[i] = max(0LL, maxi + 1 - nums[i]);
        }
        auto solve = [&](int l, int r, int target_k) -> long long {
            if (target_k == 0) return 0;
            int len = r - l + 1;
            if (len < target_k * 2 - 1) return 1e18;    
            vector<long long> prev2(target_k + 1, 1e18);
            vector<long long> prev1(target_k + 1, 1e18);
            prev2[0] = 0; 
            prev1[0] = 0;
            for (int i = 1; i <= len; i++) {
                vector<long long> curr(target_k + 1, 1e18);
                curr[0] = 0;
                long long pick = cost[l + i - 1];
                for (int j = 1; j <= target_k; j++) {
                    curr[j] = prev1[j];
                    if (prev2[j - 1] != 1e18) {
                        curr[j] = min(curr[j], prev2[j - 1] + pick);
                    }
                }
                prev2 = prev1;
                prev1 = curr;
            }
            return prev1[target_k];
        };
        long long ans = 1e18;
        ans = min(ans, solve(1, n - 1, k));
        if (k >= 1) {
            long long res = solve(2, n - 2, k - 1);
            if (res != 1e18) {
                ans = min(ans, cost[0] + res);
            }
        }
        return ans == 1e18 ? -1 : (int)ans;
    }
};