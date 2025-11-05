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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        vector<TreeNode*> preorder;
        preorderTraversal(root, preorder);
        for (int i = 1; i < preorder.size(); i++) {
            preorder[i - 1]->left = NULL;
            preorder[i - 1]->right = preorder[i];
        }
    }
    void preorderTraversal(TreeNode* root, vector<TreeNode*>& preorder) {
        if (root == NULL)
            return;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();
            preorder.push_back(root);
            if (root->right != NULL)
                st.push(root->right);
            if (root->left != NULL)
                st.push(root->left);
        }
    }
};