class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        # Initialize the grid filled entirely with walls '#'
        grid = [["#"] * n for _ in range(m)]
        
        # Clear out the entire first row (index 0)
        grid[0] = ["."] * n
        
        # Clear out the last column for every row
        for i in range(m):
            grid[i][-1] = "."
            
        # Convert each row array into a string and return the result
        return ["".join(row) for row in grid]
