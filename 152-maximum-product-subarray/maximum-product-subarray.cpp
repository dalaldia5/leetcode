class Solution {
public:
    // If number of negative elements is odd, maximum product subarray can be obtained only by excluding either the prefix till first negative or the suffix after last negative.Hence we check prefix and suffix products.
// Odd number of negatives ko even banane ke liye ek negative remove karna zaroori hota hai. Contiguous subarray me ye negative sirf ya to leftmost ho sakta hai ya rightmost.Isliye hum prefix aur suffix products ka maximum lete hain.
        int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int pref = 1;
        int suff = 1;
        for (int i = 0; i < nums.size(); i++) {
            pref *= nums[i];
            ans = max(ans, pref);
            if (pref == 0) {
                pref = 1;
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            suff *= nums[i];
            ans = max(ans, suff);
            if (suff == 0) {
                suff = 1;
            }
        }
        return ans;
    }
};