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
    int dfs(TreeNode* currNode, int maxi) {
        if (!currNode){
            return 0;
        }
        int ans=0;
        if (currNode->val>=maxi){
            ans=1;
        }
        maxi = max(maxi, currNode->val);
        ans+=dfs(currNode->left, maxi);
        ans+=dfs(currNode->right, maxi);
        return ans;
    }

    int goodNodes(TreeNode* root) { 
        return dfs(root, root->val); 
    }
};