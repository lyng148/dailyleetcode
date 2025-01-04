class Solution {
public:
    int m, n; // Dimensions of the board
    bool res = false; // Result flag

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // Visited matrix

        // Loop through every cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    // Depth-first search function
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int h, int c, int index) {
        // Check boundaries and conditions
        if (h < 0 || c < 0 || h >= m || c >= n || visited[h][c] || board[h][c] != word[index]) {
            return false;
        }

        // If we have matched all characters in the word
        if (index == word.length() - 1) {
            return true;
        }

        visited[h][c] = true; // Mark the current cell as visited

        // Explore all four directions
        bool found = dfs(board, word, visited, h + 1, c, index + 1) ||
                     dfs(board, word, visited, h - 1, c, index + 1) ||
                     dfs(board, word, visited, h, c + 1, index + 1) ||
                     dfs(board, word, visited, h, c - 1, index + 1);

        visited[h][c] = false; // Backtrack and unmark the cell
        return found;
    }
};
