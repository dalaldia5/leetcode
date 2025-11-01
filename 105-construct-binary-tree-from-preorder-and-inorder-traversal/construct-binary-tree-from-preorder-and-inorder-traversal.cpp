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
    TreeNode* func(vector<int>& preorder, int preStart, int preEnd,
                   vector<int>& inorder, int inStart, int inEnd,
                   map<int, int>& mpp) {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot =
            mpp[root->val]; // inorder traversal mein root kaha lie krta hai
        int numsLeft =
            inRoot -
            inStart; // how many no's are to the left of root in inorder
                     // traversal (how many no's to the left of root node)
        root->left = func(preorder, preStart + 1, preStart + numsLeft, inorder,
                          inStart, inRoot - 1, mpp);
        root->right = func(preorder, preStart + numsLeft + 1, preEnd, inorder,
                           inRoot + 1, inEnd, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root = func(preorder, 0, preorder.size() - 1, inorder, 0,
                              inorder.size() - 1, mpp);
        return root;
    }
};