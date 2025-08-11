class Solution {
public:
    const int MOD = 1000000007; // Modulo value as given in problem

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>
            powers; // This will store the powers of two that sum up to n

        // STEP 1: Extract all powers of two from the binary representation of n
        // We check each bit position from 0 to 30 (safely within int range)
        for (int i = 0; i <= 30; i++) {
            // (1 << i) represents 2^i
            // (n & (1 << i)) checks if the i-th bit of n is set (1)
            if (n & (1 << i)) {
                powers.push_back(1
                                 << i); // Store this power of two in the vector
            }
        }

        vector<int> ans; // This will store answers for each query

        // STEP 2: Process each query one by one
        for (int i = 0; i < queries.size(); i++) {
            long long p = 1; // Start product as 1 (multiplicative identity)

            // Each query gives a range [l, r]
            // Multiply all elements from powers[l] to powers[r]
            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                p = (p * powers[j]) %
                    MOD; // Take modulo at each step to avoid overflow
            }

            ans.push_back((int)p); // Store final product for this query
        }

        // STEP 3: Return all answers
        return ans;
    }
};
