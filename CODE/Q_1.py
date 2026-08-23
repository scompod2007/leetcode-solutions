class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        a = len(nums)
        for i in range(0, a):
            for j in range(0, a):
                if i == j:
                    continue
                else:
                    if nums[i] + nums[j] == target:
                        return [i, j]
        