import functools

class Solution:
  def numberOfSets(self, n: int, k: int) -> int:
    MOD = 1_000_000_007

    @functools.lru_cache(None)
    def dp(i: int, k: int, drawing: bool) -> int:
      if k == 0:
        return 1
      if i == n:
        return 0
      if drawing:
        return (dp(i + 1, k, True) + dp(i, k - 1, False)) % MOD
      return (dp(i + 1, k, False) + dp(i + 1, k, True)) % MOD

    return dp(0, k, False)