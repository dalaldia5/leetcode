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
                // just clearing the leftmost elements wont work since we can
                // have that element more times between l and r so instead we
                // clear the set
                set.clear();
                // now after shifting l one place aage, we insert all the
                // elements between l and r in the set
                for (int i = l; i <= r; i++) {
                    set.insert(arr[i]);
                }
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};