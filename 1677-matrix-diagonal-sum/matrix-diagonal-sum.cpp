class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        int sum = 0;

        int i = 0, j = 0;
        while (i < n && j < n) {
            if (!vis[i][j]) {
                vis[i][j] = true;
                sum += mat[i][j];
            }
            i++;
            j++;
        }

        i = 0, j = n - 1;
        while (i < n && j >= 0) {
            if (!vis[i][j]) {
                vis[i][j] = true;
                sum += mat[i][j];
            }
            i++;
            j--;
        }

        return sum;
    }
};