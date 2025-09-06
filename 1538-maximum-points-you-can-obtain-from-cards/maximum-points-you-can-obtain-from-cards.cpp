class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum = 0;   // sum of cards taken from the left
        int rSum = 0;   // sum of cards taken from the right
        int maxSum = 0; // final answer (maximum score)

        // Step 1: Take the first k cards from the left initially
        for (int i = 0; i < k; i++) {
            lSum += cardPoints[i];
        }

        // Initially, maxSum is when we take all k cards from the left
        maxSum = lSum;

        // Step 2: Now gradually shift cards from left side to right side
        // Example:
        // first check: k from left, 0 from right
        // then check: (k-1) from left, 1 from right
        // then check: (k-2) from left, 2 from right ... till all from right
        int rIndex =
            cardPoints.size() - 1; // pointer to the right end of the array

        for (int i = k - 1; i >= 0; i--) {
            // Remove one card from left sum
            lSum -= cardPoints[i];

            // Add one card from right sum
            rSum += cardPoints[rIndex];
            rIndex--;

            // Update maxSum with the better option
            maxSum = max(maxSum, lSum + rSum);
        }

        // Step 3: Return the maximum score found
        return maxSum;
    }
};
