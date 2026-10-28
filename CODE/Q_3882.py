KEEP = [sum(1 << x for x in range(1024) if not x >> k & 1) for k in range(10)]  # KEEP[k]: positions whose bit k is 0, built once


def xor_all(mask, v):  # {x ^ v for x in mask} on all 1024 bits at once
    for k, low in enumerate(KEEP):
        if v >> k & 1:
            s = 1 << k
            mask = (mask & low) << s | (mask >> s) & low  # swap each pair of s-bit blocks
    return mask


class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        dp = [1 << x for x in accumulate(grid[0], xor)]  # first row: one path to each cell, so one XOR
        for row in grid[1:]:
            dp[0] = 1 << (dp[0].bit_length() - 1 ^ row[0])  # first column: one path too
            for j in range(1, len(row)):
                dp[j] = xor_all(dp[j] | dp[j - 1], row[j])
        return (dp[-1] & -dp[-1]).bit_length() - 1  # the lowest set bit is the smallest XOR