class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        if((nums.size()==2)) {
            return nums[0]==nums[1] ? 1 : 2;
        }

        // int prev = nums[0];

        int i=0;
        int j=1;
        int count = 0;

        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }
            else{
                swap(nums[i+1], nums[j]);
                count++;
                i +=1;
                j++;
            }
        }
        return count+1;
        
    }
};