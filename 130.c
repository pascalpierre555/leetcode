#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool notFlip(char **board, int boardSize, int *boardColSize, int **visited, int i, int j, int nth) {
    bool output = 0;
    if (board[i][j] == 'X') {
        visited[i][j] = 1;
        return 0;
    }
    visited[i][j] = nth;
    if ((i - 1 >= 0) && (visited[i - 1][j] == 0)) {
        if (notFlip(board, boardSize, boardColSize, visited, i - 1, j, nth))
            output = 1;
    }
    if ((i + 1 < boardSize) && (visited[i + 1][j] == 0)) {
        if (notFlip(board, boardSize, boardColSize, visited, i + 1, j, nth))
            output = 1;
    }
    if ((j - 1 >= 0) && (visited[i][j - 1] == 0)) {
        if (notFlip(board, boardSize, boardColSize, visited, i, j - 1, nth))
            output = 1;
    }
    if ((j + 1 < boardColSize[i]) && (visited[i][j + 1] == 0)) {
        if (notFlip(board, boardSize, boardColSize, visited, i, j + 1, nth))
            output = 1;
    }
    if ((i - 1 < 0) || (i + 1 >= boardSize) || (j - 1 < 0) || (j + 1 >= boardColSize[i])) {
        output = 1;
    }
    return output;
}

void solve(char **board, int boardSize, int *boardColSize) {
    int nth = 2;
    int **visited = (int **)malloc(boardSize * sizeof(int *));
    bool *flip = (bool *)calloc(boardSize * boardColSize[0], sizeof(bool));
    for (int i = 0; i < boardSize; i++) {
        visited[i] = (int *)calloc(boardColSize[i], sizeof(int));
    }
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (visited[i][j] != 0) {
                continue;
            }
            else {
                if (notFlip(board, boardSize, boardColSize, visited, i, j, nth)) {
                    flip[nth - 2] = 1;
                }
            }
            nth++;
        }
    }
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (visited[i][j] >= 2 && !flip[visited[i][j] - 2]) {
                board[i][j] = 'X';
            }
        }
    }
    return;
}