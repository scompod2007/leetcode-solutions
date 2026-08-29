class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        sorted_with_indices = sorted(zip(nums, range(n)))
        result = [0] * n
        i = 0
        while i < n:
            j = i + 1
            while j < n and sorted_with_indices[j][0] - sorted_with_indices[j - 1][0] <= limit:
                j += 1
            original_indices = sorted(index for _, index in sorted_with_indices[i:j])
            for position, (value, _) in zip(original_indices, sorted_with_indices[i:j]):
                result[position] = value
            i = j
        return result