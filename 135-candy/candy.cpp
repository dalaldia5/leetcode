class Solution {
public:
// Children with a higher rating get more candies than their neighbors.
// iska matlab ye nhi hai ki peak element ko zyada candies deni hain, it means agar rating left se zyada hai toh left se bda do and agar right se zyada hai toh right se bda do
    int candy(vector<int>& ratings) {
        int cnt = 0;
        int n = ratings.size();
        vector<int> ans(n, 1);
        for (int i=1; i<n; i++){
            if (ratings[i]>ratings[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }
        for (int i=n-2; i>=0; i--){
            if (ratings[i]>ratings[i+1]){
                ans[i]=max(ans[i], ans[i+1]+1);
            }
        }
        for (auto it: ans){
            cnt+=it;
        }
        return cnt;
    }
};