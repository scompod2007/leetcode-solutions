class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        count = [0] * 32
        for x in nums:
            for bit in range(32):
                count[bit] += x >> bit & 1
        answer = 0
        for _ in range(k):
            x = 0
            for bit in range(32):
                if count[bit]:
                    x |= 1 << bit
                    count[bit] -= 1
            answer = (answer + x * x) % 1_000_000_007
        return answer