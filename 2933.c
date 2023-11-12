#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int translate(char *input) {
    int hr = (input[0] - '0') * 10 + (input[1] - '0');
    int min = (input[2] - '0') * 10 + (input[3] - '0');
    return hr * 60 + min;
}

char **findHighAccessEmployees(char ***access_times, int access_timesSize, int *access_timesColSize, int *returnSize) {
    char **output = (char **)calloc(access_timesSize, sizeof(char *));
    int idx = 0, idx2 = 0;
    int tmp = 0, tmp2 = 0;
    int *acced = (int *)calloc(access_timesSize, sizeof(int));
    int **time = (int **)calloc(access_timesSize, sizeof(int *));
    for (int i = 0; i < access_timesSize; i++) {

        if (acced[i] == 0) {

            acced[i] = 1;
            time[i] = calloc(access_timesSize + 5, sizeof(int));
            time[i][0] = translate(access_times[i][1]);
            time[i][1] = -1;
            time[i][2] = -1;
            for (int j = i + 1; j < access_timesSize; j++) {
                if (!strcmp(access_times[i][0], access_times[j][0])) {
                    acced[j] = 1;
                    tmp = translate(access_times[j][1]);
                    idx = -1;
                    for (int k = 0; time[i][k] > tmp; k++) {
                        idx = k;
                    }
                    for (int k = idx + 1; time[i][k] > -1; k++) {
                        tmp2 = time[i][k];
                        time[i][k] = tmp;
                        tmp = tmp2;
                        idx = k;
                    }
                    time[i][idx + 1] = tmp;
                    time[i][idx + 2] = -1;
                    time[i][idx + 3] = -1;
                }
            }
        }
    }
    for (int i = 0; i < access_timesSize; i++) {
        if (time[i] != NULL) {
            for (int j = 0; (time[i][j + 2] != -1) && (j < access_timesSize); j++) {
                printf("%d ", time[i][j]);
                printf("%d ", time[i][j + 1]);
                printf("%d ", time[i][j + 2]);
                if (abs(time[i][j] - time[i][j + 2]) < 60) {
                    output[idx2] = (char *)calloc(12, sizeof(char));
                    strcpy(output[idx2], access_times[i][0]);
                    idx2++;
                    break;
                }
            }
        }
    }
    (*returnSize) = idx2;
    return output;
}