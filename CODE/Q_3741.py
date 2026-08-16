class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        positions = {}

        for i, num in enumerate(nums):
            if num not in positions:
                positions[num] = []
            positions[num].append(i)

        ans = float('inf')

        for idx in positions.values():
            if len(idx) < 3:
                continue

            for i in range(len(idx) - 2):
                distance = 2 * (idx[i + 2] - idx[i])
                ans = min(ans, distance)

        return -1 if ans == float('inf') else ans