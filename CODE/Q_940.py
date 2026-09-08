class Solution:
	def distinctSubseqII(self, s: str) -> int:
	    MOD = 10 ** 9 + 7
	    ends = [0] * 26 
	    for ch in s:
	        idx = ord(ch) - ord('a')
	        total = sum(ends) % MOD
	        ends[idx] = (total + 1) % MOD
	    return sum(ends) % MOD