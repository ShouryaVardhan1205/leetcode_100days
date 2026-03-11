#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;

int cmp(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    return p2->freq - p1->freq;   // descending frequency
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
    int offset = 10000;
    int freq[20001] = {0};

    // Count frequencies
    for(int i = 0; i < numsSize; i++)
        freq[nums[i] + offset]++;

    // Store unique numbers with frequency
    Pair arr[numsSize];
    int count = 0;

    for(int i = 0; i < 20001; i++) {
        if(freq[i] > 0) {
            arr[count].num = i - offset;
            arr[count].freq = freq[i];
            count++;
        }
    }

    // Sort by frequency
    qsort(arr, count, sizeof(Pair), cmp);

    // Prepare result
    int* result = (int*)malloc(k * sizeof(int));
    for(int i = 0; i < k; i++)
        result[i] = arr[i].num;

    *returnSize = k;
    return result;
}