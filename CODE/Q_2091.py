class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        min_index = 0
        max_index = 0
        
        for i, num in enumerate(nums):
            if num < nums[min_index]:
                min_index = i
            if num > nums[max_index]:
                max_index = i
        
        if min_index > max_index:
            min_index, max_index = max_index, min_index
        
        return min(
            max_index + 1,
            len(nums) - min_index,
            min_index + 1 + len(nums) - max_index
        )