#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to print the Sudoku board
void print(int board[][9], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n"); 
    }
}

// Function to check if placing a number is valid
bool isvalid(int board[][9], int n, int i, int j, int num) {
    // Row and column check
    for (int x = 0; x < n; x++) {
        if (board[i][x] == num || board[x][j] == num) {
            return false;
        }
    }
    
    // Subgrid check
    int rn = sqrt(n);  
    int si = i - i % rn;
    int sj = j - j % rn;
    for (int x = si; x < si + rn; x++) {
        for (int y = sj; y < sj + rn; y++) {
            if (board[x][y] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku board using backtracking
bool sudokosolver(int board[][9], int i, int j, int n) {
    // BASE CASE: If reached the end of the board
    if (i == n) {
        print(board, n);
        return true;
    }

    // If we reached the end of the current row, move to the next row
    if (j == n) {
        return sudokosolver(board, i + 1, 0, n);
    }

    // If the cell is already filled, move to the next cell
    if (board[i][j] != 0) {
        return sudokosolver(board, i, j + 1, n);
    }

    // Try placing numbers from 1 to 9 in the current cell
    for (int num = 1; num <= 9; num++) {
        // Check if the number can be placed
        if (isvalid(board, n, i, j, num)) {
            board[i][j] = num;  // Place the number

            // Recursively solve the next cell
            if (sudokosolver(board, i, j + 1, n)) {
                return true;
            }

            // Backtrack if the solution is not found
            board[i][j] = 0;
        }
    }

    return false;  
}

int main() {
    int n = 9;
    int board[9][9]=
{
    {0,0,7,1,0,0,0,6,0},
    {1,0,5,2,0,8,0,0,0},
    {6,0,0,0,0,7,0,0,0},
    {3,1,2,4,0,5,0,0,8},
    {0,0,6,0,9,0,2,0,0},
    {0,0,0,0,0,3,0,0,1},
    {0,0,1,0,0,4,9,8,6},
    {8,0,3,9,0,6,0,0,0},
    {0,6,0,0,8,2,7,0,3},

};
sudokosolver(board,0,0,n);
 return 0;
}