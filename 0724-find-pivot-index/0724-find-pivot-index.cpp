class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix(nums.size());
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            prefix.push_back(sum);
            sum +=nums[i];
        }

        int sum_suff = 0;
        for(int j=nums.size()-1; j>=0; j--){
            suffix[j] = sum_suff;
            sum_suff += nums[j];
        }

        int n = 0;
        int m = 0;
        while(n<nums.size()){
            if(prefix[n] == suffix[n]) return n;
            n++;
        }
        return -1;
    }
};