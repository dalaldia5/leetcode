class Solution {
public:
    // find(k, n) -> minimum attempts needed
    // jab k eggs aur n floors available ho
    int find(int k, int n, vector<vector<int>>& dp) {

        // Base case:
        // Agar floors 0 ya 1 hain
        // toh utne hi attempts lagenge
        if (n == 0 || n == 1)
            return n;

        // Agar sirf 1 egg hai
        // toh har floor pe ek-ek karke drop karna padega
        if (k == 1)
            return n;

        // Agar answer already calculated hai
        // toh directly return kar do
        if (dp[k][n] != -1)
            return dp[k][n];

        int ans = INT_MAX;

        // Binary search lagane ke liye
        int l = 1, h = n;

        // Binary search isliye possible hai kyunki:
        // left (egg break case) -> increasing function
        // right (egg survive case) -> decreasing function

        while (l <= h) {

            int mid = (l + h) / 2;

            // Case 1: Egg break ho gaya
            // -> neeche ke floors check karne padenge
            // -> eggs bhi kam ho jaayenge
            int left = find(k - 1, mid - 1, dp);

            // Case 2: Egg nahi toota
            // -> upar ke floors check karne padenge
            // -> eggs same rahenge
            int right = find(k, n - mid, dp);

            // Worst case lena zaroori hai
            // kyunki egg ka behaviour unpredictable hai
            int temp = 1 + max(left, right);

            // Minimum worst-case attempts store karte hain
            ans = min(ans, temp);

            // Ab binary search ka logic:
            if (left < right) {
                // Agar egg survive case zyada costly hai (costly->more number of attempts)
                // toh upar ki floors pe jao
                // kyunki worst case right side me hai
                l = mid + 1;
            } else {
                // Agar egg break case zyada costly hai
                // toh neeche ki floors pe jao
                h = mid - 1;
            }
        }

        // Final answer dp me store karke return
        return dp[k][n] = ans;
    }

    int superEggDrop(int K, int N) {
        // dp[k][n] = minimum attempts with k eggs and n floors
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, -1));

        return find(K, N, dp);
    }
};
