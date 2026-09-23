class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        target_sum = sum(nums) - x
        prefix_sum_index = {0: -1}
        max_length = -1
        current_sum = 0

        for index, value in enumerate(nums):
            current_sum += value

            if current_sum not in prefix_sum_index:
                prefix_sum_index[current_sum] = index

            required_prefix = current_sum - target_sum
            if required_prefix in prefix_sum_index:
                subarray_length = index - prefix_sum_index[required_prefix]
                max_length = max(max_length, subarray_length)

        return -1 if max_length == -1 else len(nums) - max_length