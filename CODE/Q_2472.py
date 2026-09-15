class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        from functools import cache

        @cache
        def find_max_palindromes(start_index: int) -> int:
            if start_index >= string_length:
                return 0

            max_count = find_max_palindromes(start_index + 1)

            for end_index in range(start_index + k - 1, string_length):
                if is_palindrome[start_index][end_index]:
                    max_count = max(max_count, 1 + find_max_palindromes(end_index + 1))

            return max_count

        string_length = len(s)
        is_palindrome = [[True] * string_length for _ in range(string_length)]

        for start in range(string_length - 1, -1, -1):
            for end in range(start + 1, string_length):
                is_palindrome[start][end] = (
                    s[start] == s[end] and is_palindrome[start + 1][end - 1]
                )

        result = find_max_palindromes(0)
        find_max_palindromes.cache_clear()

        return result