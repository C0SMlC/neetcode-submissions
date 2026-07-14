class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        requiredEleAndIndexMap = {}

        for index, num in enumerate(nums):
            if num in requiredEleAndIndexMap:
                return [requiredEleAndIndexMap[num], index]
            
            requiredEleAndIndexMap[target- num] = index

        
        return []