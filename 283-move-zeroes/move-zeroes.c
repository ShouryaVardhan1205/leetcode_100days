void moveZeroes(int* nums, int numsSize) {
    int j = 0;  // position for next non-zero element

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != 0) {
            // swap nums[i] and nums[j]
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
}
