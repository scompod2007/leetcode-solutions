import math

class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        ans = 0
        
        # 1. Find all valid divisors of n
        divisors = []
        for i in range(1, int(math.isqrt(n)) + 1):
            if n % i == 0:
                divisors.append(i)
                if i * i != n:
                    divisors.append(n // i)
        
        # 2. Check each factor k
        for k in divisors:
            possible = True
            prev_max = float('-inf')
            
            for start in range(0, n, k):
                block = nums[start : start + k]
                
                # Check condition 1: At most one drop in a circular block
                drops = 0
                for i in range(k):
                    if block[i] > block[(i + 1) % k]:
                        drops += 1
                
                if drops > 1:
                    possible = False
                    break
                
                # Check condition 2: Inter-block order mapping
                block_min = min(block)
                if block_min < prev_max:
                    possible = False
                    break
                
                prev_max = max(block)
                
            if possible:
                ans += k
                
        return ans
