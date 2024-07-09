# Roman Olsen
# Leetcode top 150
# Summary ranges
#
import List


class Solution:

    def range_to_text(self, range: List[int]) -> str:
        if len(range) == 1:
            return str(range[0])
        return str(range[0]) + "->" + str(range[-1])

    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums) == 0:
            return []
        ranges = []
        current_range = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] != (current_range[-1] + 1):
                ranges.append(self.range_to_text(current_range))
                current_range.clear()
                current_range.append(nums[i])
            elif nums[i] == current_range[-1] + 1:
                current_range.append(nums[i])
        if len(current_range) != 0:
            ranges.append(self.range_to_text(current_range))
        return ranges
