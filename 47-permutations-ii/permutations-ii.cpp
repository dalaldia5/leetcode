class Solution {
public:
    void func(int n, vector<vector<int>>& ans, vector<int>& temp, unordered_map<int, int>& mpp){
        // if our current vector's size becomes equal to the size of initial givem aray, then it is a possible answer
        if (temp.size()==n){
            ans.push_back(temp);
        }
        for (auto& [num, cnt]: mpp){
            // mpp ----> 1->2, 2->1
            // if that element is not available in map, can't add
            if (cnt==0){
                continue;
            }
            // if element is available in map, then we can push it back
            // [1]
            temp.push_back(num);
            // reduce its occurrence
            // 1->1, 2->1
            mpp[num]--;
            func(n, ans, temp, mpp); // let's say: [1,1] || [1,2]
                                    // mpp----> 1->0, 2->1 || 1->1, 2->0
                                    // [1,1,2] || [1,2,1]
            temp.pop_back();
            mpp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // for final ans
        vector<vector<int>> ans;
        int n=nums.size();
        // map to store all occurrences of elements since we can have duplicates
        unordered_map<int, int> mpp;
        // store number of occurrences of each element
        // mpp ----> 1->2, 2->1
        for (auto &it: nums){
            mpp[it]++;
        }
        vector<int> temp;
        func(n, ans, temp, mpp);
        return ans;
    }
};