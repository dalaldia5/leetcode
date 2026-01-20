class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mpp;
        for (auto it : arr) {
            mpp[it]++;
        }
        vector<int> freq;
        for (auto it: mpp){
            freq.push_back(it.second);
        }
        int unique=freq.size();
        sort(freq.begin(), freq.end());
        for (auto it: freq){
            if (k>=it){
                k-=it;
                unique--;
            }
            else {
                continue;
            }
        }
        return unique;
    }
};