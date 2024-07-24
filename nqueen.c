#include <stdio.h>
#include <stdbool.h>

#define N 4

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void solveNQUtil(int board[N][N], int col, int* count) {
    if (col >= N) {
        (*count)++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            solveNQUtil(board, col + 1, count);
            board[i][col] = 0; // BACKTRACK
        }
    }
}

int main() {
    int board[N][N] = {0};
    int count = 0;

    solveNQUtil(board, 0, &count);

    printf("Number of solutions: %d\n", count);
    return 0;
}
