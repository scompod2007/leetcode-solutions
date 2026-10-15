from typing import List

class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        
        # Iterate over all possible starting positions
        for i in range(n):
            distinct_elements = set()
            # Expand the subarray rightward
            for j in range(i, n):
                distinct_elements.add(nums[j])
                # Calculate distinct count, square it, and add to sum
                ans += len(distinct_elements) ** 2
                
        return ans
