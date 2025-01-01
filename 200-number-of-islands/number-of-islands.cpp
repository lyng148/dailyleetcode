class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int res = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    res++;
                    stack<pair<int, int>> myStack;
                    myStack.push(make_pair(i, j));
                    while (!myStack.empty()) {
                        pair<int, int> myPair = myStack.top();
                        myStack.pop();
                        int x = myPair.first, y = myPair.second;

                        if (visited[x][y]) continue;
                        visited[x][y] = true;

                        // Duyệt 4 hướng
                        if (x > 0 && grid[x - 1][y] == '1' && !visited[x - 1][y]) {
                            myStack.push(make_pair(x - 1, y));
                        }
                        if (x < m - 1 && grid[x + 1][y] == '1' && !visited[x + 1][y]) {
                            myStack.push(make_pair(x + 1, y));
                        }
                        if (y > 0 && grid[x][y - 1] == '1' && !visited[x][y - 1]) {
                            myStack.push(make_pair(x, y - 1));
                        }
                        if (y < n - 1 && grid[x][y + 1] == '1' && !visited[x][y + 1]) {
                            myStack.push(make_pair(x, y + 1));
                        }
                    }
                }
            }
        }
        return res;
    }
};
