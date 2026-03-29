class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // {value,index}
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);
        for (int i = k; i < nums.size(); i++) {
            pq.push({nums[i], i});
            // remove elements outside window
            while (pq.top().second <= i - k) {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};