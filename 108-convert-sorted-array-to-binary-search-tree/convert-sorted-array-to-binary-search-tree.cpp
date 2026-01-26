/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if (nums.empty()){
            return NULL;
        }
        TreeNode* root=new TreeNode(nums[n/2]);
        vector<int> nums1;
        vector<int> nums2;
        for (int i=0; i<n/2;i++) {
            nums1.push_back(nums[i]);
        }
        for (int i=n/2+1; i<n; i++) {
            nums2.push_back(nums[i]);
        }
        root->left=sortedArrayToBST(nums1);
        root->right=sortedArrayToBST(nums2);
        return root;
    }
};