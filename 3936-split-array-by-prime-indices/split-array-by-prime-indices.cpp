class Solution {
private:
    bool isPrime(int n) {
        int cnt = 0;
        if (n <= 1)
            return 0;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

public:
    long long splitArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        long long sum1 = 0, sum2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (isPrime(i))
                arr1.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }
        for (auto x : arr1) {
            sum1 += x;
        }
        for (auto y : arr2) {
            sum2 += y;
        }
        return llabs(sum1 - sum2);
    }
};