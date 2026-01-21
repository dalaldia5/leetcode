class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int reqdIndex = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= x) {
                reqdIndex = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int l, r;
        vector<int> ans;
        if (reqdIndex + 1 < n &&
            abs(arr[reqdIndex + 1] - x) < abs(arr[reqdIndex] - x)) {
            ans.push_back(arr[reqdIndex + 1]);
            l = reqdIndex;
            r = reqdIndex + 2;
        } else {
            ans.push_back(arr[reqdIndex]);
            l = reqdIndex - 1;
            r = reqdIndex + 1;
        }

        k--;

        while (k > 0 && (l >= 0 || r < n)) {
            if (l >= 0 && r < n) {
                if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                    ans.push_back(arr[l--]);
                } else {
                    ans.push_back(arr[r++]);
                }
            } else if (l >= 0) {
                ans.push_back(arr[l--]);
            } else {
                ans.push_back(arr[r++]);
            }
            k--;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
