class Solution {
private:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // check upper diagonal
        int duprow = row;
        int dupcol = col;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        // check in same row
        col = dupcol; // resetting row and col values
        row = duprow;
        while (col >= 0) { // row will remain same
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        // checking lower diagonal
        col = dupcol; // resetting row and col values
        row = duprow;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }

public:
    void solve(int col, vector<string>& board, int n,
               vector<vector<string>>& ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, n, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n);
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        solve(0, board, n, ans);
        return ans;
    }
};