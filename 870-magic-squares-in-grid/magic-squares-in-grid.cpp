class Solution {
public:
    bool isMagicGrid(vector<vector<int>>& grid, int rStart, int cStart) {
        vector<int> nums;
        for (int i = rStart; i < rStart + 3; i++) {
            for (int j = cStart; j < cStart + 3; j++) {
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        // checking if all the numbers from 1-9 are there in the subgrid
        for (int k = 0; k < 9; k++) {
            if (nums[k] != k + 1)
                return false;
        }
        int sum = grid[rStart][cStart] + grid[rStart][cStart + 1] +
                  grid[rStart][cStart + 2];

        // check sum of all rows is equal to sum
        for (int i = rStart; i < rStart + 3; i++) {
            if (grid[i][cStart] + grid[i][cStart + 1] + grid[i][cStart + 2] !=
                sum) {
                return false;
            }
        }

        // check sum of all columns is equal to sum
        for (int i = cStart; i < cStart + 3; i++) {
            if (grid[rStart][i] + grid[rStart + 1][i] + grid[rStart + 2][i] !=
                sum) {
                return false;
            }
        }
        // check sum of all diagonals is equal to sum
        if (grid[rStart][cStart] + grid[rStart + 1][cStart + 1] +
                grid[rStart + 2][cStart + 2] !=
            sum) {
            return false;
        }
        if (grid[rStart][cStart + 2] + grid[rStart + 1][cStart + 1] +
                grid[rStart + 2][cStart] !=
            sum) {
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
        int r = grid.size();
        int c = grid[0].size();

        // iterating over each possible 3x3 subgrid
        for (int i = 0; i <= r - 3; i++) {
            for (int j = 0; j <= c - 3; j++) {
                if (isMagicGrid(grid, i, j)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};