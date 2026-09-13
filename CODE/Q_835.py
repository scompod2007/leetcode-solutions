class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        translation_count = Counter()

        for row1 in range(n):
            for col1 in range(n):
                if img1[row1][col1] == 1:
                    for row2 in range(n):
                        for col2 in range(n):
                            if img2[row2][col2] == 1:
                                translation_vector = (row1 - row2, col1 - col2)
                                translation_count[translation_vector] += 1

        return max(translation_count.values()) if translation_count else 0