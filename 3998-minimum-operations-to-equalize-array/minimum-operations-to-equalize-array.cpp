class Solution {
public:
    // As in one operation, we can change all the elements of a range to the
    // bitwise & of that range. We can simply pick the entire array as the range
    // and change all the elements to the bitwise & which takes one operation.
    // So the best answer will always be either 0 if all the elements of the
    // array are already same, else 1.
    int minOperations(vector<int>& nums) {
        int cnt = count(nums.begin(), nums.end(), nums[0]);
        return cnt < nums.size() ? 1 : 0;
    }
};