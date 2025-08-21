#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>
            freqMap; // Stores frequency of elements in the current window
        long long maxSum = 0; // Final answer: maximum sum of a valid subarray
        long long windowSum = 0; // Current sliding window sum
        int left = 0;            // Left pointer of the sliding window

        // Iterate with right pointer over the array
        for (int right = 0; right < nums.size(); right++) {
            // Add current element to the window
            freqMap[nums[right]]++;
            windowSum += nums[right];

            // Check if the window size exceeds k
            if (right - left + 1 == k) {
                // Condition: window should have exactly k distinct elements
                if (freqMap.size() == k) {
                    maxSum = max(maxSum, windowSum);
                }

                // Slide the window forward by removing the leftmost element
                windowSum -= nums[left];
                freqMap[nums[left]]--;

                // If frequency becomes 0, remove the element completely from
                // map
                if (freqMap[nums[left]] == 0) {
                    freqMap.erase(nums[left]);
                }

                // Move left boundary ahead
                left++;
            }
        }

        return maxSum;
    }
};
