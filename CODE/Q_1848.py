class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        """
        Find the minimum distance between the start index and any index where target appears.
      
        Args:
            nums: List of integers to search through
            target: The target value to find in the list
            start: The starting index to measure distance from
          
        Returns:
            The minimum absolute distance from start to any occurrence of target
        """
        # Find all indices where the target value appears
        # Calculate the absolute distance from each target index to the start index
        # Return the minimum distance among all target occurrences
        return min(abs(index - start) for index, value in enumerate(nums) if value == target)