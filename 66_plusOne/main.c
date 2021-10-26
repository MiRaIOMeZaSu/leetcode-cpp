#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize) {
    // 可以通过指针的移动防止进位
    digits[digitsSize - 1] += 1;
    int *ret = malloc(sizeof(int) * (digitsSize + 1));
    ret[0] = 0;
    for (int i = digitsSize - 1; i >= 0; i--) {
        ret[i + 1] = digits[i];
    }
    for (int i = digitsSize; i >= 1; i--) {
        ret[i - 1] += ret[i] / 10;
        ret[i] = ret[i] % 10;
    }
    if (ret[0] != 0) {
        *returnSize = digitsSize + 1;
        return ret;
    } else {
        ret++;
        *returnSize = digitsSize;
        return ret;
    }
}

int main() {
    int nums[] = {9, 9, 9};
    int *retSize = malloc(sizeof(int));
    int *ret;
    ret = plusOne(nums, 3, retSize);
    for (int i = 0; i < *retSize; i++) {
        printf("%d", ret[i]);
    }
    return 0;
}
