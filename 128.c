#include <stdio.h>
#include <stdlib.h>
#include <uthash.h>

typedef struct Hash {
    int key;
    int len;
    UT_hash_handle hh;
} Hash;

int longestConsecutive(int *nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }
    int lenMax = 1;
    Hash *map = NULL;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i] + 1000000000;
        Hash *s;
        HASH_FIND_INT(map, &num, s);
        if (s != NULL) {
            continue;
        }
        else {
            int prevNum = num - 1;
            int nextNum = num + 1;
            Hash *prev, *next;
            HASH_FIND_INT(map, &prevNum, prev);
            HASH_FIND_INT(map, &nextNum, next);
            s = (Hash *)malloc(sizeof(Hash *));
            s->key = num;
            if ((prev == NULL) && (next == NULL)) {
                s->len = 1;
                HASH_ADD_INT(map, key, s);
            }
            else if (prev == NULL) {
                s->len = next->len + 1;
                HASH_ADD_INT(map, key, s);
                nextNum = num + next->len;
                HASH_FIND_INT(map, nextNum, next);
                next->len += 1;
                if (s->len > lenMax) {
                    lenMax = s->len;
                }
            }
            else if (next == NULL) {
                s->len = prev->len + 1;
                HASH_ADD_INT(map, key, s);
                prevNum = num - prev->len;
                HASH_FIND_INT(map, prevNum, prev);
                prev->len += 1;
                if (s->len > lenMax) {
                    lenMax = s->len;
                }
            }
            else {
                HASH_ADD_INT(map, key, s);
                prevNum = num - prev->len;
                HASH_FIND_INT(map, prevNum, prev);
                prev->len += (1 + next->len);
                nextNum = num + next->len;
                HASH_FIND_INT(map, nextNum, next);
                next->len = prev->len;
                if (next->len >= lenMax) {
                    lenMax = next->len;
                }
            }
        }
    }
    return lenMax;
}