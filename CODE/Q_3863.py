from itertools import pairwise

class Solution:
    def minOperations(self, s: str) -> int:
        # If already sorted
        if all(a <= b for a, b in pairwise(s)):
            return 0
        
        # Two letters out of order cannot be sorted with proper substrings
        if len(s) == 2:
            return -1
        
        mn, mx = min(s), max(s)
        
        # If the smallest char is at the front or largest char is at the back
        if s[0] == mn or s[-1] == mx:
            return 1
            
        # If min or max char sits somewhere in the middle
        if any(c in [mn, mx] for c in s[1:-1]):
            return 2
            
        # Worst-case scenario requires 3 operations
        return 3
