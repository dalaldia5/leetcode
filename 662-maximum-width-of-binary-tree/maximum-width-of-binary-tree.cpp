class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long mmin = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                long long curr_idx = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0)
                    first = curr_idx;
                if (i == size - 1)
                    last = curr_idx;
                if (node->left)
                    q.push({node->left, curr_idx * 2 + 1});
                if (node->right)
                    q.push({node->right, curr_idx * 2 + 2});
            }
            maxWidth = max(maxWidth, last - first + 1);
        }
        return maxWidth;
    }
};
