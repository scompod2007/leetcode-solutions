int search(int* nums, int numsSize, int target) {
    int start = 0;
    int end = numsSize - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // Check if left half is sorted
        if (nums[mid] >= nums[start]) {
            if (target >= nums[start] && target < nums[mid]) {
                end = mid - 1; // Search left
            } else {
                start = mid + 1; // Search right
            }
        } 
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[end]) {
                start = mid + 1; // Search right
            } else {
                end = mid - 1; // Search left
            }
        }
    }

    return -1;
}