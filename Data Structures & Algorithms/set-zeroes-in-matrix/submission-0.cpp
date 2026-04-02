class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        vector<vector<int>> mark = matrix;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (matrix[i][j] == 0) {
                    for (int col = 0; col < COLS; col++) {
                        mark[i][col] = 0;
                    }
                    for (int row = 0; row < ROWS; row++) {
                        mark[row][j] = 0;
                    }
                }
            }
        }
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                matrix[r][c] = mark[r][c];
            }
        }
    }
};
