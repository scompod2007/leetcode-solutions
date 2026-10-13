class Solution:
    def maxAlternatingSum(self, nums: list[int]) -> int:
        # Convert all numbers to their squares and sort them
        squares = sorted(x * x for x in nums)
        
        # The first k elements are the smallest squares to be subtracted
        k = len(nums) // 2
        
        # Return sum of the upper half minus the sum of the lower half
        return sum(squares[k:]) - sum(squares[:k])
