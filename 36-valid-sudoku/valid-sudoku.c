bool check(char** board, int row, int col, char target) {
    for (int i = 0; i < 9; i++) {
        if (i != row && board[i][col] == target)
            return false;
        if (i != col && board[row][i] == target)
            return false;
    }

    int rowStart = row - row % 3;
    int colStart = col - col % 3;

    for (int i = rowStart; i < rowStart + 3; i++) {
        for (int j = colStart; j < colStart + 3; j++) {
            if ((i != row || j != col) && board[i][j] == target)
                return false;
        }
    }

    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    for (int i = 0; i < 9 ; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.' && !check(board, i, j, board[i][j]))
                return false;
        }
    }
    return true;
}
