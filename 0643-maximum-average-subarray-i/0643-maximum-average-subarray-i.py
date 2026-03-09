class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        i=0
        sum = 0
        for i in range (k):
            sum+=nums[i]
        avg_sum = sum/k
        m=0
        n=k
        while(n<len(nums)):
            sum = sum + nums[n] - nums[m] 
            n +=1
            m +=1
            avg_sum = max(avg_sum, sum/k)
        return avg_sum
        
        