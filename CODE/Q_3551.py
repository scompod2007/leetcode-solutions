class Solution:

  def minSwaps(self, nums: List[int]) -> int:

    def get_digit_sum(x: int) -> int:
      s = 0
      while x:
        s += x % 10
        x //= 10
      return s

    n = len(nums)
    # Create sorted target arrangement based on (digit_sum, value)
    arr = sorted((get_digit_sum(x), x) for x in nums)
    # Map each value to its target index
    target_idx = {val: idx for idx, (_, val) in enumerate(arr)}

    ans = n
    vis = [False] * n

    # Count cycles in the permutation graph
    for i in range(n):
      if not vis[i]:
        ans -= 1
        j = i
        while not vis[j]:
          vis[j] = True
          j = target_idx[nums[j]]

    return ans
