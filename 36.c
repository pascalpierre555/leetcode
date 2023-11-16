#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isValidSudoku(char **board, int boardSize, int *boardColSize) {
    int tmp;
    bool **row = (bool **)calloc(9, sizeof(bool *));
    for (int i = 0; i < 9; i++) {
        row[i] = (bool *)calloc(9, sizeof(bool));
    }
    bool **column = (bool **)calloc(9, sizeof(bool *));
    for (int i = 0; i < 9; i++) {
        column[i] = (bool *)calloc(9, sizeof(bool));
    }
    bool **box = (bool **)calloc(9, sizeof(bool *));
    for (int i = 0; i < 9; i++) {
        box[i] = (bool *)calloc(9, sizeof(bool));
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] = '.') {
                continue;
            }
            tmp = board[i][j] - '0';
            if (row[i][tmp] == 0) {
                row[i][tmp] = 1;
            }
            else {
                return 0;
            }
            if (column[j][tmp] == 0) {
                column[j][tmp] = 1;
            }
            else {
                return 0;
            }
            if (box[((i / 3) * 3) + j / 3][tmp] == 0) {
                box[((i / 3) * 3) + j / 3][tmp] = 1;
            }
            else {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    return 0;
}