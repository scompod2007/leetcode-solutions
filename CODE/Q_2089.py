class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        # Count how many numbers are smaller than the target
        less_than = sum(1 for num in nums if num < target)
        
        # Count how many times the target appears
        count = nums.count(target)
        
        # Generate the continuous range of indices
        return list(range(less_than, less_than + count))
