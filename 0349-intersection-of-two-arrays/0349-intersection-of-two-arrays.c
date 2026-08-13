#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size,
                  int* nums2, int nums2Size,
                  int* returnSize) {

    // Acts like a hash set
    int hash[1001] = {0};

    // Store elements of nums1
    for (int i = 0; i < nums1Size; i++) {
        hash[nums1[i]] = 1;
    }

    // Maximum possible result size
    int* result = malloc(sizeof(int) * 1001);

    int k = 0;

    // Check elements of nums2
    for (int i = 0; i < nums2Size; i++) {

        if (hash[nums2[i]] == 1) {

            result[k] = nums2[i];
            k++;

            // Set to 0 so duplicate isn't added
            hash[nums2[i]] = 0;
        }
    }

    *returnSize = k;

    return result;
}