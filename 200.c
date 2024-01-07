#include <stdio.h>
#include <stdlib.h>

void search(int i, int j, char **grid, int gridSize, int *gridColSize, int **visited) {
    if ((i - 1 >= 0) && (visited[i - 1][j] == 0)) {
        visited[i - 1][j] = 1;
        if (grid[i - 1][j] == '1') {
            search(i - 1, j, grid, gridSize, gridColSize, visited);
        }
    }
    if ((i + 1 < gridSize) && (visited[i + 1][j] == 0)) {
        visited[i + 1][j] = 1;
        if (grid[i + 1][j] == '1') {
            search(i + 1, j, grid, gridSize, gridColSize, visited);
        }
    }
    if ((j - 1 >= 0) && (visited[i][j - 1] == 0)) {
        visited[i][j - 1] = 1;
        if (grid[i][j - 1] == '1') {
            search(i, j - 1, grid, gridSize, gridColSize, visited);
        }
    }
    if ((j + 1 < gridColSize[i]) && (visited[i][j + 1] == 0)) {
        visited[i][j + 1] = 1;
        if (grid[i][j + 1] == '1') {
            search(i, j + 1, grid, gridSize, gridColSize, visited);
        }
    }
    return;
}

int numIslands(char **grid, int gridSize, int *gridColSize) {
    int output = 0;
    int **visited = (int **)malloc(gridSize * sizeof(int *));
    for (int i = 0; i < gridSize; i++) {
        visited[i] = (int *)calloc(gridColSize[i], sizeof(int));
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (visited[i][j] != 0) {
                continue;
            }
            else {
                visited[i][j] = 1;
                if (grid[i][j] == '1') {
                    output++;
                    search(i, j, grid, gridSize, gridColSize, visited);
                }
            }
        }
    }
    return output;
}