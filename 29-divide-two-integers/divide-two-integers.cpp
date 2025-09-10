class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special case: if dividend and divisor are equal, result is always 1
        if (dividend == divisor)
            return 1;

        // Determine the sign of the result
        // 'true' means positive, 'false' means negative
        bool sign = true;
        if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor >= 0))
            sign = false;

        // Use long to avoid overflow when taking abs(INT_MIN)
        long n = abs((long)dividend);
        long d = abs((long)divisor);

        long ans = 0; // Final result

        // Keep subtracting divisor multiples until dividend is smaller
        while (n >= d) {
            int cnt = 0;

            // Keep doubling divisor (using left shift) until it exceeds n
            // d << (cnt+1) means d * 2^(cnt+1)
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }

            // Add the corresponding power of 2 to quotient
            ans += (1 << cnt);

            // Subtract the largest found multiple from n
            n -= (d << cnt);
        }

        // Handle overflow case:
        // If ans equals 2^31, it exceeds INT_MAX when positive
        if (ans == (1 << 31) && sign)
            return INT_MAX;

        // If ans equals 2^31, it equals INT_MIN when negative
        if (ans == (1 << 31) && !sign)
            return INT_MIN;

        // Return ans with proper sign
        return sign ? ans : -ans;
    }
};
