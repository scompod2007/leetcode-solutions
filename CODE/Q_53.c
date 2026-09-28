#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize) {
    int res = nums[0];
    int total = 0;

    for (int i = 0; i < numsSize; i++) {
        if (total < 0) {
            total = 0;
        }

        total += nums[i];
        res = MAX(res, total);
    }

    return res;
}