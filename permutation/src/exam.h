#ifndef EXAM_H
#define EXAM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int res_count = 0;

void swap(char *a, char *b) {
    char t;
    t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(char *nums) {
    if (nums == NULL)
        return;

    int numsSize = strlen(nums);
    for (int i = numsSize - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (*(nums + j) > *(nums + j + 1)) {
                swap(&(*(nums + j)), &(*(nums + j + 1)));
            }
        }
    }
}


void AllPermutation(char *perm, int from, int to, char **res) {
    if (from == to) {
        memcpy(res[res_count], perm, strlen(perm));
        res_count++;
    }

    if (from < to) {
        for (int j = from; j <= to; j++) {
            swap(&perm[j], &perm[from]);
            AllPermutation(perm, from + 1, to, res);
            swap(&perm[j], &perm[from]);
        }
    }
}


void ArrayInvertedSequence(char **ss, int NN) {
    char **ps, *tp;
    int i, j, k, m, x;

    m = strlen(ss[0]);

    for (i = 0; i < NN; i++) {
        for (j = i + 1; j < NN; j++) {
            for (x = 0; x < m; x++) {
                if (ss[i][x] == ss[j][x]) {
                    continue;
                }
                if (ss[i][x] > ss[j][x]) {
                    tp = ss[i];
                    ss[i] = ss[j];
                    ss[j] = tp;
                    break;
                } else {
                    break;
                }
            }
        }
    }
}

char **permute_string(const char *input) {
    char **res = 0;
    int N = 1;

    char *tmp = (char *) malloc(sizeof(char *) * (strlen(input) + 1));
    memset(tmp, 0, strlen(tmp) + 1);
    memcpy(tmp, input, strlen(input));
    //bubbleSort(tmp);

    for (int i = strlen(input); i > 1; i--) {
        N = N * i;
    }

    res = (char **) malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++) {
        res[i] = (char *) malloc(sizeof(char) * (strlen(input) + 1));
        memset(res[i], 0, strlen(input) + 1);
    }

    AllPermutation(tmp, 0, strlen(tmp) - 1, res);
    res[N] = 0;
    res_count = 0;

    ArrayInvertedSequence(res, N);

    /* TODO */
    return res;
}


#endif // EXAM_H
