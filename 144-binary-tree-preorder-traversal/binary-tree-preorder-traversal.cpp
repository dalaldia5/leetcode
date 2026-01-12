/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorderFunc(vector<int>& preorder, TreeNode* root){
        if (root==NULL){
            return;
        }
        preorder.push_back(root->val);
        preorderFunc(preorder, root->left);
        preorderFunc(preorder, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        preorderFunc(preorder, root);
        return preorder;
    }
};