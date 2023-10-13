bool check(char** board, int row, int col, int target) {
    int colStart = col - (col % 3);
    int rowStart = row - (row % 3);

    for (int i = rowStart; i <= rowStart + 2; i++) {
        for (int j = colStart; j <= colStart + 2; j++) {
            if (board[i][j] == target)
                return false;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (board[row][i] == target)
            return false;
        if (board[i][col] == target)
            return false;
    }
    return true;
}

bool thu(char** board, int row, int col)
{   
    if (row == 9)
    {
        return true;
    }

    if (board[row][col] == '.')
    {
        for (int j = '1'; j <= '9'; j++)
        {
            if (check(board, row, col, j))
            {
                board[row][col] = j;
                bool next;
                if (col == 8)
                    next = thu(board, row + 1, 0);
                else 
                    next = thu(board, row, col + 1);
                
                if(next) return true; // If the next call returns true, stop the recursion
                
                board[row][col] = '.'; // If the next call returns false, unmake the current move
            }
        }
    }
    else
    {
        bool next;
        if (col == 8)
            next = thu(board, row + 1, 0);
        else 
            next = thu(board, row, col + 1);
        
        if(next) return true;
    }
    
    return false; // Return false if no valid number can be placed in this cell
}


void solveSudoku(char** board, int boardSize, int* boardColSize){
    thu(board, 0, 0);
}