class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_set<int> set;
        int l = 0;
        int maxlen = 0;

        for (int r = 0; r < arr.size(); r++) {
            set.insert(arr[r]);
            if (set.size() > 2) {
                l++;
                set.clear();
                for (int i = l; i <= r; i++) {
                    set.insert(arr[i]);
                }
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};