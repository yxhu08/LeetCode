#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size,
                  int* nums2, int nums2Size,
                  int* returnSize) {

    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int maxSize = nums1Size < nums2Size ? nums1Size : nums2Size;

    int* result = malloc(sizeof(int) * maxSize);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nums1Size && j < nums2Size) {

        if (nums1[i] == nums2[j]) {

            if (k == 0 || result[k - 1] != nums1[i]) {
                result[k] = nums1[i];
                k++;
            }

            i++;
            j++;
        }

        else if (nums1[i] < nums2[j]) {
            i++;
        }

        else {
            j++;
        }
    }

    *returnSize = k;

    return result;
}