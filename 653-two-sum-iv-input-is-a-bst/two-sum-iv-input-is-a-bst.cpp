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
    vector<int> ans;
    vector<int> inorder(TreeNode* root){
        if (!root){
            return ans;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        return ans;
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int n=ans.size();
        int l=0, r=n-1;
        while (l<r){
            int m=l+(r-l)/2;
            if (ans[l]+ans[r]==k){
                return true;
            }
            else if (ans[l]+ans[r]<k){
                l++;
            }
            else {
                r--;
            }
        }
        return false;
    }
};