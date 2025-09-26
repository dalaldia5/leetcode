class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        // If there are fewer than 3 numbers, no triangle
        if (n < 3) {
            return 0;
        }

        // Step 1: Sort the array.
        // If a <= b <= c, then a + c > b and b + c > a are always true
        // (since c is the largest and a, b are positive).
        // We only need to check the condition a + b > c.
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through the array to fix the longest side 'c'.
        // 'k' represents the index of the longest side (nums[k]).
        // We start from the end (n-1) and go down to index 2,
        // because we need at least two other elements (at indices i and j)
        // to form a triangle.
        for (int k = n - 1; k >= 2; k--) {
            // 'nums[k]' is fixed as the potential longest side of the triangle.

            // Step 3: Use two pointers 'i' and 'j' to find pairs for the two
            // shorter sides 'a' and 'b'. 'i' starts at the beginning of the
            // array (index 0). 'j' starts just before 'k' (index k-1).
            int i = 0;
            int j = k - 1;

            // Loop while 'i' is less than 'j'. This ensures we are considering
            // two distinct shorter sides from the remaining unsorted part of
            // the array to the left of 'k'.
            while (i < j) {
                // Check the triangle inequality: nums[i] + nums[j] > nums[k]
                // Since the array is sorted, nums[i] <= nums[j] <= nums[k].
                // The other two conditions (nums[i] + nums[k] > nums[j] and
                // nums[j] + nums[k] > nums[i]) are automatically satisfied
                // because nums[k] is the largest.
                if (nums[i] + nums[j] > nums[k]) {
                    // If the condition is true, it means nums[i], nums[j],
                    // nums[k] can form a triangle. Because the array is sorted,
                    // any number between nums[i] and nums[j] (i.e., nums[i],
                    // nums[i+1], ..., nums[j-1]) when paired with nums[j] will
                    // also satisfy the condition nums[x] + nums[j] > nums[k].
                    // This is because nums[x] >= nums[i].
                    // So, all pairs (nums[i], nums[j]), (nums[i+1], nums[j]),
                    // ..., (nums[j-1], nums[j]) will form a valid triangle with
                    // nums[k]. There are (j - i) such pairs. Add this count to
                    // the total.
                    cnt += (j - i);

                    // Now, decrement 'j' to look for a smaller 'b' side.
                    // By doing this, we might find more pairs with nums[i]
                    // (or elements to its right) that sum up to be greater than
                    // nums[k].
                    j--;
                } else {
                    // If nums[i] + nums[j] <= nums[k], it means the sum of the
                    // two shorter sides is not large enough to form a triangle
                    // with nums[k]. To increase the sum, we need a larger 'a'
                    // side. Increment 'i' to move to the next potential 'a'
                    // side.
                    i++;
                }
            }
        }

        // Return the total count of valid triangles.
        return cnt;
    }
};