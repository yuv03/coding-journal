class Solution:
    def pivotIndex(self, nums: List[int]) -> int:

        prefix = []
        suffix = [0]*len(nums)

        sum_pre = 0
        for i in range(len(nums)):
            prefix.append(sum_pre)
            sum_pre += nums[i]
        
        sum_suff = 0
        
        for i in range(len(nums)-1,-1,-1):
            suffix[i] = sum_suff
            sum_suff += nums[i]

        n =0
        while n< len(nums):
            if(prefix[n]==suffix[n]): return n
            n +=1
        return -1
        