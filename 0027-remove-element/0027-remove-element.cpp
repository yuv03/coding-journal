class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        if(nums.size()==1){
            if(nums[0]!=val) return 1;
            else return 0; 
        }
        int i=0;
        int j=1;
        int count = 0;

        // [1,2]   val=3
        while(i<nums.size() && j<nums.size()){
            if(nums[i] != val) {
                i++;
                j++;
                count++;
            }
            else{
                if(nums[j] != val){
                    swap(nums[i] , nums[j]);
                    count++;
                    i++;
                    j++;
                }
                else{
                    j++;
                }
            }
        }
        if(i<nums.size()){
            if(nums[i] != val) count++;
        }
        return count;
    }
};