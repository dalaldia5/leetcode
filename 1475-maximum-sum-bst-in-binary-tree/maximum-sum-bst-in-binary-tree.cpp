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

class helper {
public:
    int maxi;
    int mini;
    bool isBST;
    int sum;
};
// postorder traversal coz bottom up
helper func(TreeNode* root, int& ans) {
    if (!root) {
        // return {maxi, mini, isBST, maxSum}
        return {INT_MIN, INT_MAX, true, 0};
    }
    helper left = func(root->left, ans);
    helper right = func(root->right, ans);
    helper curr;
    if (left.isBST && right.isBST && left.maxi < root->val &&
        root->val < right.mini) {
        curr.isBST = true;
        curr.mini = min(root->val, left.mini);
        curr.maxi = max(root->val, right.maxi);
        curr.sum = left.sum + right.sum + root->val;
        ans = max(ans, curr.sum);
    } else {
        curr.isBST = false;
        curr.sum = 0;
        curr.mini = INT_MIN;
        curr.maxi = INT_MAX;
    }
    return curr;
}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        func(root, maxSum);
        return maxSum;
    }
};